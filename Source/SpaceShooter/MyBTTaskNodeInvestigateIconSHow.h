// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTaskNodeInvestigateIconSHow.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UMyBTTaskNodeInvestigateIconSHow : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UMyBTTaskNodeInvestigateIconSHow();

	UPROPERTY(EditAnywhere, Category = "Investigate Icon")
	bool bShowIcon = true;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
