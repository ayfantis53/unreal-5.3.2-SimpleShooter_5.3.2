// Fill out your copyright notice in the Description page of Project Settings.
// Change Mobility of component to movable in Transform Properties
#pragma once

// Unreal headers
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SS_Door_open_component.generated.h"


class ATriggerVolume;

/**
 *	An actor component that gives our doors funtionality to move when activated by trigger volumes
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SIMPLESHOOTER_API USS_Door_open_component : public UActorComponent
{
	GENERATED_BODY()

public:	
	/// @brief Sets default values for this component's properties.
	USS_Door_open_component();

	/// @brief
	/// @param delta_time
	/// @param tick_type
	/// @param this_tick_function
	auto TickComponent(float delta_time, ELevelTick tick_type, FActorComponentTickFunction* this_tick_function) -> void override;

protected:
	/// @brief Called when the game starts.
	auto BeginPlay() -> void override;

	/// @brief 
	/// @param delta_time
	auto open_door(float delta_time) -> void;

	/// @brief 
	/// @param delta_time
	auto close_door(float delta_time) -> void;

	/// @brief 
	/// @param delta_time
	auto activate_trigger_volume(float delta_time) -> void;

private:
	/// @brief Get Initial position of the door.
	float initial_z_;

	/// @brief 
	float current_z_;

	/// @brief Where I want the door to be after opening .
	float target_z_;

	/// @brief make sure door doesnt loop sounds over eachother if character triggers pressure plate alot.
	bool b_door_sound_;

	/// @brief Only player can open doors not AI.
	AActor* actor_opens_door_;
	
	/// @brief 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	ATriggerVolume* pressure_plate_;

	/// @brief 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	class USoundCue* door_opening_sound_;
};
