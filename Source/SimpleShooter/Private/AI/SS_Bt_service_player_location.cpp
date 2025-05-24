// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/SS_Bt_service_player_location.h"

// Unreal includes
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


USS_Bt_service_player_location::USS_Bt_service_player_location()
{
	NodeName = TEXT("Update Player Location");
}

auto USS_Bt_service_player_location::TickNode(UBehaviorTreeComponent& owner_comp, uint8* node_memory, float delta_seconds) -> void
{
	Super::TickNode(owner_comp, node_memory, delta_seconds);

	APawn* player_pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (player_pawn == nullptr)
	{
		return;
	}

	owner_comp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), player_pawn->GetActorLocation());
}


