// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Weapons/SS_Gun_rifle.h"
#include "Weapons/SS_Gun_launcher.h"
#include "Weapons/SS_Gun_shotgun.h"
#include "Weapons/SS_Gun_sniper.h"

// Unreal headers
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SS_Shooter_character.generated.h"


class UCameraComponent;
class USpringArmComponent;
class USkeletalMeshComponent;

/**
 *	Base class for Player and Enemy shooter characters
 */
UCLASS(Abstract)
class SIMPLESHOOTER_API ASS_Shooter_character : public ACharacter
{
	GENERATED_BODY()

public:
	/// @brief Sets default values for this character's properties.
	ASS_Shooter_character() = default;

	/// @brief Sets default value for acceleration path to true.
	ASS_Shooter_character(const FObjectInitializer& ObjectInitializer);

	/// @brief Getters for anim class.
	FORCEINLINE auto get_aiming()  const -> bool { return b_aiming_; }
	FORCEINLINE auto get_is_dead() const -> bool { return b_is_dead_; }

	/// @brief Setters for enemy class.
	FORCEINLINE auto set_aiming(bool b_aiming) -> void { b_aiming_ = b_aiming; }

	/// @brief Apply damage to this actor.
	/// @param damage_amount    How much damage to apply.
	/// @param damage_event     Data package that fully describes the damage received.
	/// @param event_instigator The Controller responsible for the damage.
	/// @param damage_causer    The Actor that directly caused the damage (e.g. the projectile that exploded, the rock that landed on you).
	/// @return The amount of damage actually applied.
	auto TakeDamage(float damage_amount, struct FDamageEvent const& damage_event, class AController* event_instigator, AActor* damage_causer) -> float override;

	/// @brief Fires weapon at player and applies damage to that character depending on weapon.
	auto shoot() -> void;

	/// @brief Stop firing of weapon and stop particle effects.
	auto stop_shoot() -> void;

protected:
	/// @brief Called when the game starts or when spawned.
	auto BeginPlay() -> void override;

	/// @brief setup of all constructor helpers to get paths of assets.
	virtual auto setup_character() -> void PURE_VIRTUAL();

	/// @brief
	auto start_fire_timer() -> void;

	/// @brief
	auto auto_fire_reset() -> void;

	/// @brief No damage taken for a certain amount of time, health regenerates.
	void recharge_health();

	/// @brief What we will set the character mesh to.
	UPROPERTY()
	USkeletalMeshComponent* character_mesh_;

	/// @brief path to animation blueprint we will use for this shooter character.
	FString anim_bp_file_path_{ "AnimBlueprint'/Game/AssetPacks/ParagonWraith/Characters/Heroes/Wraith/ABP_Shooter_character.ABP_Shooter_character'" };

	//// GENERAL HEALTH /////

	/// @brief players current health.
	float health_;

	/// @brief players max health.
	float max_health_{ 400.f };

	/// @brief is this player dead?
	bool b_is_dead_{ false };

	/// @brief should this character's health regenerate?
	bool b_recharge_{ false };

	/// @brief
	FTimerHandle timer_handle_shield_recharge_;

	//// AIM HELPERS ////

	/// @brief is this character aiming?
	bool b_aiming_{ false };

	/// @brief
	float zoom_interp_speed_{ 20.f };

	/// @brief
	float camera_default_fov_{ 0.f };

	/// @brief
	float camera_current_fov_{ 0.f };

	//// FIRING HELPERS ////

	/// @brief
	class ASS_Gun_base* gun_ref_{ nullptr };

	/// @brief Different firing animations for different weapons.
	UPROPERTY()
	UAnimMontage* hip_fire_montage_;

	/// @brief montage of character firing different weapons path.
	FString hip_fire_montage_path_{ "AnimMontage'/Game/AssetPacks/ParagonWraith/Characters/Heroes/Wraith/Animations/FireWeapon_Montage.FireWeapon_Montage'" };

	/// @brief boolean to control whether out gun fires automatic or not.
	bool b_should_fire_{ true };

	/// @brief tells us if we are firing weapon or not.
	bool b_fire_button_pressed_{ false };

	/// @brief 
	FTimerHandle auto_fire_timer_;

};
