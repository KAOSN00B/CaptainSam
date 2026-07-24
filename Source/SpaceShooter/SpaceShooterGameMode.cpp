// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaceShooterGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "SpaceShooterCharacter.h"
#include "SpaceShooterPlayerController.h"
#include "ShooterAI.h"

ASpaceShooterGameMode::ASpaceShooterGameMode()
{
	// stub
}

void ASpaceShooterGameMode::BeginPlay()
{
	Super::BeginPlay();

	ASpaceShooterCharacter* Player = Cast<ASpaceShooterCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	TArray<AActor*> ShooterAIActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShooterAI::StaticClass(), ShooterAIActors);
	UE_LOG(LogTemp, Warning, TEXT("Found ShooterAI actors: %d"), ShooterAIActors.Num());

	for(AActor* ShooterAIActor : ShooterAIActors)
	{
		AShooterAI* ShooterAI = Cast<AShooterAI>(ShooterAIActor);
		if(ShooterAI)
		{
			ShooterAI->StartBehaviorTree(Player);

			ASpaceShooterCharacter* EnemyCharacter = Cast<ASpaceShooterCharacter>(ShooterAI->GetPawn());
			RegisterEnemy(EnemyCharacter);
		}
	}

	if (ASpaceShooterPlayerController* PlayerController = Cast<ASpaceShooterPlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
	{
		PlayerController->SetEnemiesRemaining(GetEnemiesRemaining());
	}
}

void ASpaceShooterGameMode::RegisterEnemy(ASpaceShooterCharacter* Enemy)
{
	if (Enemy)
	{
		EnemiesInLevel.AddUnique(Enemy);
	}
}

void ASpaceShooterGameMode::NotifyEnemyDied(ASpaceShooterCharacter* Enemy)
{
	if (Enemy)
	{
		EnemiesInLevel.Remove(Enemy);
	}

	if (ASpaceShooterPlayerController* PlayerController = Cast<ASpaceShooterPlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
	{
		PlayerController->SetEnemiesRemaining(GetEnemiesRemaining());
	}

	if (!bIsAlarmSoundPlaying && GetEnemiesRemaining() <= 3)
	{
		bIsAlarmSoundPlaying = true;

		if (AlarmSound)
		{
			UGameplayStatics::PlaySound2D(this, AlarmSound);

		}

		TriggerPlayerInvestigate();
		

	}
}

int32 ASpaceShooterGameMode::GetEnemiesRemaining() const
{
	return EnemiesInLevel.Num();
}

void ASpaceShooterGameMode::TriggerPlayerChase(bool TriggerChase) const
{
	for (ASpaceShooterCharacter* Enemy : EnemiesInLevel)
	{
		if (!Enemy)
		{
			continue;
		}
		if (Enemy)
		{
			AShooterAI* ShooterAI = Cast<AShooterAI>(Enemy->GetController());
			if (ShooterAI)
			{
				ShooterAI->SetPlayerChase(TriggerChase);
			}
		}
	}

}

void ASpaceShooterGameMode::TriggerPlayerInvestigate() const
{
	for (ASpaceShooterCharacter* Enemy : EnemiesInLevel)
	{
		if (!Enemy)
		{
			continue;
		}

		AShooterAI* ShooterAI = Cast<AShooterAI>(Enemy->GetController());
		if (ShooterAI)
		{
			ShooterAI->SetPlayerInvestigate();
		}
	}
}
