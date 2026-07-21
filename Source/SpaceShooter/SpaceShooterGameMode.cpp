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
	UE_LOG(LogTemp, Warning, TEXT("Enemies registered: %d"), EnemiesInLevel.Num());
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
}

int32 ASpaceShooterGameMode::GetEnemiesRemaining() const
{
	return EnemiesInLevel.Num();
}
