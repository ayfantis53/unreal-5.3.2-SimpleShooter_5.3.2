// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/SS_Bt_task_clear_value.h"

// Unreal includes
#include "BehaviorTree/BlackboardComponent.h"


USS_Bt_task_clear_value::USS_Bt_task_clear_value()
{
	NodeName = TEXT("Clear Backboard Value");
}

auto USS_Bt_task_clear_value::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory) -> EBTNodeResult::Type
{
	Super::ExecuteTask(owner_comp, node_memory);

	owner_comp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult::Succeeded;
}