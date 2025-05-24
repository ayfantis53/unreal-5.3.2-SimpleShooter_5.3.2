// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

// Unreal headers
#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "SS_Bt_service_seen_player.generated.h"


/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API USS_Bt_service_seen_player : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	/// @brief Sets Name of BlackBoard Node.
	USS_Bt_service_seen_player();

protected:
	/// @brief Tick function this function should be considered as const (don't modify state of object) if node is not instanced!
	/// @param owner_comp    The behavior tree owner of this node.
	/// @param node_memory   The instance memory of the current node.
	/// @param delta_seconds DeltaTime since last call.
	auto TickNode(UBehaviorTreeComponent& owner_comp, uint8* node_memory, float delta_seconds) -> void override;

private:
	/// @brief FX of a sound played for when Enemy gun shoots.
	UPROPERTY()
	USoundBase* battle_cry_;

	/// @brief FX of a sound played for when Enemy spots player.
	FString battle_cry_path_{ "SoundCue'/Game/AssetPacks/GameDevTV/VoiceOvers/A_EnemySpeak_Cue.A_EnemySpeak_Cue'" };

	/// @brief Control to make sure many enemies do not speak all at once.
	bool speak_{ true };
};
