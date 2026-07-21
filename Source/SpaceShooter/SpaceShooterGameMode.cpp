// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaceShooterGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "SpaceShooterCharacter.h"
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


	for(AActor* ShooterAIActor : ShooterAIActors)
	{
		AShooterAI* ShooterAI = Cast<AShooterAI>(ShooterAIActor);
		if(ShooterAI)
		{
			ShooterAI->StartBehaviorTree(Player);
		}
	}
}
