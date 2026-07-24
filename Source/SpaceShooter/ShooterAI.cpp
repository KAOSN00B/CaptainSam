// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAI.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SpaceShooterGameMode.h"

void AShooterAI::BeginPlay()
{
	Super::BeginPlay();

}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AShooterAI::StartBehaviorTree(ASpaceShooterCharacter* Player)
{

	if (EnemyAIBehaviorTree)
	{

		MyCharacter = Cast<ASpaceShooterCharacter>(GetPawn());
		if (Player)
		{
			PlayerCharacter = Player;
		}

		RunBehaviorTree(EnemyAIBehaviorTree);

		UBlackboardComponent* MyBlackboard = GetBlackboardComponent();
		if(MyBlackboard && MyCharacter)
		{
			MyBlackboard->SetValueAsBool("IsAlert", false);
			MyBlackboard->SetValueAsVector("StartLocation", MyCharacter->GetActorLocation());
			MyBlackboard->ClearValue("PlayerLocation");
			MyBlackboard->ClearValue("LastKnownPlayerLocation");

		}

	}
}

void AShooterAI::SetPlayerChase(bool SetAlert)
{
	UBlackboardComponent* MyBlackboard = GetBlackboardComponent();

	if (!MyBlackboard)
	{
		return;
	}

	MyBlackboard->SetValueAsBool("IsAlert", SetAlert);

	if (SetAlert && PlayerCharacter)
	{
		MyBlackboard->SetValueAsVector("PlayerLocation", PlayerCharacter->GetActorLocation());
		MyBlackboard->SetValueAsVector("LastKnownPlayerLocation", PlayerCharacter->GetActorLocation());
	}
}

void AShooterAI::SetPlayerInvestigate()
{
	UBlackboardComponent* MyBlackboard = GetBlackboardComponent();

	if (!MyBlackboard || !PlayerCharacter)
	{
		return;
	}

	MyBlackboard->SetValueAsBool("IsAlert", false);
	MyBlackboard->ClearValue("PlayerLocation");
	MyBlackboard->SetValueAsVector("LastKnownPlayerLocation", PlayerCharacter->GetActorLocation());
}
