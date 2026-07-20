// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(SceneRoot);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SceneRoot);

	MuzzleFlashParticleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Muzzle Flash"));
	MuzzleFlashParticleSystem->SetupAttachment(SceneRoot);

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();

	MuzzleFlashParticleSystem->Deactivate();

}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	
	if (OwnerController)
	{
		MuzzleFlashParticleSystem->Activate(true);
		FVector ViewLocation;
		FRotator ViewRotation;
		OwnerController->GetPlayerViewPoint(ViewLocation, ViewRotation);

		FVector EndLocation = ViewLocation + ViewRotation.Vector() * MaxRange;
		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());

		bool IsHit = GetWorld()->LineTraceSingleByChannel(HitResult, 
			ViewLocation, EndLocation, ECC_GameTraceChannel2, Params);

		if (IsHit)
		{
			///DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 5.0f, 16, FColor::Red, true);
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactParticleSystem, 
				HitResult.ImpactPoint, HitResult.ImpactPoint.Rotation());

			AActor* HitActor = HitResult.GetActor();
			UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *GetNameSafe(HitActor));
			if (HitActor)
			{
				UE_LOG(LogTemp, Warning, TEXT("About to apply %.2f damage to %s"),
					BulletDamage,
					*GetNameSafe(HitActor)
				);

				const float AppliedDamage = UGameplayStatics::ApplyDamage(HitActor, BulletDamage,
					OwnerController, this, UDamageType::StaticClass());

				UE_LOG(LogTemp, Warning, TEXT("ApplyDamage returned %.2f"), AppliedDamage);
			}
			
		}

		
	}
}

