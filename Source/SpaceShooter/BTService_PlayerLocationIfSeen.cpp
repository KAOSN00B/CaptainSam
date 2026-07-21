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
	ToPlayer.Normalize();

	FVector EnemyForward = EnemyPawn->GetActorForwardVector();

	float Dot = FVector::DotProduct(EnemyForward, ToPlayer);
	bool bPlayerIsInFront = Dot > 0.5f;
	UE_LOG(LogTemp, Warning, TEXT("Dot: %f"), Dot);
	if (OwnerController->LineOfSightTo(Player) && bPlayerIsInFront)
	{
		Blackboard->SetValueAsVector("PlayerLocation", Player->GetActorLocation());
		Blackboard->SetValueAsVector("LastKnownPlayerLocation", Player->GetActorLocation());
		OwnerController->SetFocus(Player);
	}
	else
	{
		Blackboard->ClearValue("PlayerLocation");
		OwnerController->ClearFocus(EAIFocusPriority::Gameplay);
	}
}

