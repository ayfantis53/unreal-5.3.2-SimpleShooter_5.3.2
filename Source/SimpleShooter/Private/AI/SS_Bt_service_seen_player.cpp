// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/SS_Bt_service_seen_player.h"
#include "Characters/SS_Shooter_character.h"

// Unreal includes
#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


USS_Bt_service_seen_player::USS_Bt_service_seen_player()
{
	NodeName = TEXT("Update Player Location If Seen");

	static ConstructorHelpers::FObjectFinder<USoundBase> battle_cry_container(*battle_cry_path_);
	if (battle_cry_container.Succeeded())
	{
		battle_cry_ = battle_cry_container.Object;
	}
}

auto USS_Bt_service_seen_player::TickNode(UBehaviorTreeComponent& owner_comp, uint8* node_memory, float delta_seconds) -> void
{
	Super::TickNode(owner_comp, node_memory, delta_seconds);

	APawn* player_pawn					   = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	ASS_Shooter_character* enemy_character = Cast<ASS_Shooter_character>(owner_comp.GetAIOwner()->GetPawn());

	// Make sure nothing is null so game doesnt crash.
	if (!player_pawn || !enemy_character || !owner_comp.GetAIOwner())
	{
		return;
	}

	// If Enemy sees player it fills in value for player location.
	if (owner_comp.GetAIOwner()->LineOfSightTo(player_pawn))
	{
		owner_comp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), player_pawn->GetActorLocation());
		// Dieing Sound Animation.
		if (battle_cry_ && speak_)
		{
			UGameplayStatics::SpawnSoundAttached(battle_cry_, enemy_character->GetMesh(), TEXT("HealthBar"));
			speak_ = false;
		}

	}
	// If loses sight clears value and stops aiming.
	else
	{
		owner_comp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
		enemy_character->stop_shoot();
		enemy_character->set_aiming(false);
		speak_ = true;
	}
}