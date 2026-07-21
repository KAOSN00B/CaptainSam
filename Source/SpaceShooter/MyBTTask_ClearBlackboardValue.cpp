// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_ClearBlackboardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTTask_ClearBlackboardValue::UMyBTTask_ClearBlackboardValue()
{
	// Set the node name for the behavior tree task
	NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UMyBTTask_ClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	//GetBlackboard comp
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	if (Blackboard)
	{
		//clear the value of the blackboard key
		Blackboard->ClearValue(GetSelectedBlackboardKey());
		
	}
	return EBTNodeResult::Succeeded;
}
