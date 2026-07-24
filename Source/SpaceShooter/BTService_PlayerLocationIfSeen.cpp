// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSeen.h"
#include "ShooterAI.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
	NodeName = TEXT("Update Player Location If Seen");
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AShooterAI* OwnerController = Cast<AShooterAI>(OwnerComp.GetAIOwner());
	if (!OwnerController)
	{
		return;
	}

	APawn* EnemyPawn = OwnerController->GetPawn();
	ASpaceShooterCharacter* Player = OwnerController->PlayerCharacter;
	UBlackboardComponent* Blackboard = OwnerController->GetBlackboardComponent();

	if (!EnemyPawn || !Player || !Blackboard)
	{
		return;
	}

	FVector ToPlayer = Player->GetActorLocation() - EnemyPawn->GetActorLocation();
	if (!ToPlayer.Normalize())
	{
		return;
	}

	FVector EnemyForward = EnemyPawn->GetActorForwardVector();

	float Dot = FVector::DotProduct(EnemyForward, ToPlayer);
	bool bPlayerIsInFront = Dot > 0.5f;
	bool bIsAlert = Blackboard->GetValueAsBool("IsAlert");

	bool bHasLineOfSight = OwnerController->LineOfSightTo(Player);
	bool bCanSeePlayer = bHasLineOfSight && bPlayerIsInFront;

	float DistanceToPlayer = FVector::Dist(Player->GetActorLocation(), EnemyPawn->GetActorLocation());
	bool bPlayerIsInShootingRange = DistanceToPlayer <= 1000.0f;

	bool bCanShootPlayer = bHasLineOfSight && bPlayerIsInShootingRange;
	Blackboard->SetValueAsBool("CanShootPlayer", bCanShootPlayer);

	if (bIsAlert || bCanSeePlayer)
	{
		Blackboard->SetValueAsVector("PlayerLocation", Player->GetActorLocation());
		Blackboard->SetValueAsVector("LastKnownPlayerLocation", Player->GetActorLocation());

		if (bHasLineOfSight)
		{
			OwnerController->SetFocus(Player);
		}
		else
		{
			OwnerController->ClearFocus(EAIFocusPriority::Gameplay);
		}
	}
	else
	{
		Blackboard->ClearValue("PlayerLocation");
		OwnerController->ClearFocus(EAIFocusPriority::Gameplay);
	}
}

