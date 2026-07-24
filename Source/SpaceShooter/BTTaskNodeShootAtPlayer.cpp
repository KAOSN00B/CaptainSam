// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNodeShootAtPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterAI.h"

UBTTaskNodeShootAtPlayer::UBTTaskNodeShootAtPlayer()
{
	NodeName = TEXT("Shoot At Player");
}

EBTNodeResult::Type UBTTaskNodeShootAtPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AShooterAI* OwnerController = Cast<AShooterAI>(OwnerComp.GetAIOwner());

    if (OwnerController)
    {
        UBlackboardComponent* Blackboard = OwnerController->GetBlackboardComponent();

        if (!Blackboard || !Blackboard->GetValueAsBool("CanShootPlayer"))
        {
            return EBTNodeResult::Failed;
        }

        ASpaceShooterCharacter* OwnerCharacter = OwnerController->MyCharacter;
        ASpaceShooterCharacter* PlayerCharacter = OwnerController->PlayerCharacter;

        if (OwnerCharacter && PlayerCharacter && PlayerCharacter->IsAlive)
        {
            OwnerCharacter->Shoot();
            return EBTNodeResult::Succeeded;
        }
    }

    return EBTNodeResult::Failed;
}