// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SpaceShooterCharacter.h"
#include "ShooterAI.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API AShooterAI : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 300.0f;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* EnemyAIBehaviorTree;

	ASpaceShooterCharacter* PlayerCharacter;
	ASpaceShooterCharacter* MyCharacter;

public:

	virtual void Tick(float DeltaTime) override;

	void StartBehaviorTree(ASpaceShooterCharacter* Player);
	
};
