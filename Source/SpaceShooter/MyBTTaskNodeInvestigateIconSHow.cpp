// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTaskNodeInvestigateIconSHow.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "SpaceShooterCharacter.h"

UMyBTTaskNodeInvestigateIconSHow::UMyBTTaskNodeInvestigateIconSHow()
{
	NodeName = TEXT("Set Investigate Icon");
}

EBTNodeResult::Type UMyBTTaskNodeInvestigateIconSHow::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* OwnerController = OwnerComp.GetAIOwner();
	if (!OwnerController)
	{
		return EBTNodeResult::Failed;
	}

	ASpaceShooterCharacter* EnemyCharacter = Cast<ASpaceShooterCharacter>(OwnerController->GetPawn());
	if (!EnemyCharacter)
	{
		return EBTNodeResult::Failed;
	}

	EnemyCharacter->SetInvestigateIconVisible(bShowIcon);
	return EBTNodeResult::Succeeded;
}
