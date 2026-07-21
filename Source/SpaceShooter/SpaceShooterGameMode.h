// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceShooterGameMode.generated.h"

class ASpaceShooterCharacter;

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class ASpaceShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	ASpaceShooterGameMode();

	UPROPERTY()
	TArray<TObjectPtr<ASpaceShooterCharacter>> EnemiesInLevel;

	void RegisterEnemy(ASpaceShooterCharacter* Enemy);
	void NotifyEnemyDied(ASpaceShooterCharacter* Enemy);
	int32 GetEnemiesRemaining() const;

protected:
	virtual void BeginPlay() override;

};



