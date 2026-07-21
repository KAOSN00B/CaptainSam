// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNodeShootAtPlayer.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UBTTaskNodeShootAtPlayer : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTaskNodeShootAtPlayer();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
