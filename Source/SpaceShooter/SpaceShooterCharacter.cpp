// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaceShooterCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Gun.h"
#include "InputActionValue.h"
#include "SpaceShooter.h"
#include "SpaceShooterGameMode.h"
#include "SpaceShooterPlayerController.h"
#include "ShooterAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

ASpaceShooterCharacter::ASpaceShooterCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	InvestigateIconWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Investigate Icon"));
	InvestigateIconWidget->SetupAttachment(RootComponent);
	InvestigateIconWidget->SetRelativeLocation(FVector(0.f, 0.f, 130.f));
	InvestigateIconWidget->SetDrawSize(FVector2D(64.f, 64.f));
	InvestigateIconWidget->SetWidgetSpace(EWidgetSpace::Screen);
	InvestigateIconWidget->SetVisibility(false);
}

void ASpaceShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	OnTakeAnyDamage.AddDynamic(this, &ASpaceShooterCharacter::OnDamageTaken);
	SetInvestigateIconVisible(false);


	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	Gun->OwnerController = GetController();
	if (Gun)
	{
		Gun->SetOwner(this);

		Gun->AttachToComponent(
			GetMesh(),
			FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			TEXT("WeaponSocket")
		);

		Gun->OwnerController = GetController();
	}
}

void ASpaceShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		if (JumpAction)
		{
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		}

		// Moving
		if (MoveAction)
		{
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASpaceShooterCharacter::Move);
		}

		// Mouse looking
		if (MouseLookAction)
		{
			EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ASpaceShooterCharacter::Look);
		}

		// Gamepad looking
		if (LookAction)
		{
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASpaceShooterCharacter::Look);
		}

		// Shooting
		if (ShootAction)
		{
			EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &ASpaceShooterCharacter::Shoot);
		}
	}
	else
	{
		UE_LOG(LogSpaceShooter, Error, TEXT("'%s' failed to find an Enhanced Input component."), *GetNameSafe(this));
	}
}

void ASpaceShooterCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	DoMove(MovementVector.X, MovementVector.Y);
}

void ASpaceShooterCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void ASpaceShooterCharacter::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void ASpaceShooterCharacter::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void ASpaceShooterCharacter::DoJumpStart()
{
	Jump();
}

void ASpaceShooterCharacter::DoJumpEnd()
{
	StopJumping();
}

void ASpaceShooterCharacter::OnDamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{

	if (IsAlive)
	{
		if (!IsPlayerControlled())
		{
			AShooterAI* DamagedEnemy = Cast<AShooterAI>(GetController());
			if (DamagedEnemy)
			{
				UBlackboardComponent* Blackboard = DamagedEnemy->GetBlackboardComponent();
				APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

				if (Blackboard && PlayerPawn)
				{
					Blackboard->SetValueAsBool("IsAlert", false);
					Blackboard->ClearValue("PlayerLocation");
					Blackboard->SetValueAsVector("LastKnownPlayerLocation", PlayerPawn->GetActorLocation());
				}
			}
		}

		CurrentHealth -= Damage;
		UpdateHUD();
		if (CurrentHealth <= 0.0f)
		{

			IsAlive = false;
			CurrentHealth = 0.0f;
			SetInvestigateIconVisible(false);

			GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

			if (!IsPlayerControlled())
			{
				ASpaceShooterGameMode* GameMode = Cast<ASpaceShooterGameMode>(UGameplayStatics::GetGameMode(this));
				if (GameMode)
				{
					GameMode->NotifyEnemyDied(this);
				}
			}

			DetachFromControllerPendingDestroy();

		}
		
	}
}


void ASpaceShooterCharacter::Shoot()
{
	if (Gun)
	{
		Gun->PullTrigger();
	}
	else
	{
		UE_LOG(LogSpaceShooter, Warning, TEXT("Shoot called, but Gun is null."));
	}
}

void ASpaceShooterCharacter::SetInvestigateIconVisible(bool bVisible)
{
	if (InvestigateIconWidget)
	{
		InvestigateIconWidget->SetVisibility(bVisible);
	}
}

void ASpaceShooterCharacter::UpdateHUD()
{
	ASpaceShooterPlayerController* PlayerController = Cast<ASpaceShooterPlayerController>(GetController());

	if (PlayerController)
	{
		float NewPercent = CurrentHealth / MaxHealth;
		PlayerController->HUDWidget->SetHealthPercent(NewPercent);
	}
}
