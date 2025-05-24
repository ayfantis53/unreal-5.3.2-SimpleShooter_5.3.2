// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

// Unreal headers
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SS_Gun_base.generated.h"


class ASS_Projectile;

/**
 *	Base class for all gun weapons in game
 */
UCLASS()
class SIMPLESHOOTER_API ASS_Gun_base : public AActor
{
	GENERATED_BODY()
	
public:	
	/// @brief Sets default values for this actor's properties.
	ASS_Gun_base();

	/// @brief Called every frame.
	/// @param delta_time time taken between the frames of the gameplay can differ.
	auto Tick(float delta_time) -> void override;

	/// @brief fires weapon with line trace or projectile depending on weapon type.
	auto pull_trigger() -> void;

	/// @brief resets automatic fire and any lingering emitter from muzzle fire.
	auto release_trigger() -> void;

	/// @brief All Getters for Shooter Character class to use. 
	FORCEINLINE auto get_b_automatic()         const -> bool    { return b_automatic_;         }
	FORCEINLINE auto get_camera_zoomed_fov()   const -> float   { return camera_zoomed_fov_;   }
	FORCEINLINE auto get_automatic_fire_rate() const -> float   { return automatic_fire_rate_; }
	FORCEINLINE auto get_weapon_fire_montage() const -> FString { return weapon_fire_montage_; }

protected:
	/// @brief Called when the game starts or when spawned.
	auto BeginPlay() -> void override;

	/// @brief Use Constructor helpers to populate all properties.
	virtual auto setup_paths() -> void PURE_VIRTUAL();

	/* --------------------- COMPONENTS --------------------- */

	//// POINTERS TO COMPONENTS ////

	/// @brief root to place our weapon.
	UPROPERTY()
	USceneComponent* root_comp_;

	/// @brief skeletal mesh of our gun meant to be sent to children.
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* mesh_comp_;

	/// @brief where the line trace or projectiles will spawn for firing effects.
	UPROPERTY(VisibleAnywhere)
	USceneComponent* projectile_spawn_point_;

	/// @brief FX for muzzle fire will be unique for each fun.
	UPROPERTY(VisibleAnywhere)
	UParticleSystem* muzzle_flash_;

	/// @brief Stores the particle system that way we can cancel it for the infinite emitter.
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* muzzle_flash_comp_;

	/// @brief FX of when line trace hits an object (actor).
	UPROPERTY(VisibleAnywhere)
	UParticleSystem* bullet_impact_;

	/* ---------------------- EFFECTS ----------------------- */

	//// SOUND ////

	/// @brief FX of a sound played for when gun shoots.
	UPROPERTY()
	USoundBase* muzzle_sound_;

	/// @brief FX of a sound played for when bullet hits another actor.
	UPROPERTY()
	USoundBase* impact_sound_;

	//// PARTICLE EFFECTS ////

	/// @brief FX of bullet path leaving gun.
	UPROPERTY()
	UParticleSystem* bullet_trail_;

	//// ANIMATIONS ////

	/// @brief Name of the firing montage to play based on weapon.
	FString weapon_fire_montage_{ "Fire Rifle" };

	/* --------------------- PROPERTIES --------------------- */

	/// @brief default damage of weapon.
	float damage_{ 40.f };

	/// @brief how far a bullet will do damage.
	float max_range_{ 5000.f };

	/// @brief default zoom of weapon.
	float camera_zoomed_fov_{ 60.f };

	/// @brief boolean to tell us if this class is a launcher or gun class.
	bool b_is_projectile_class_{ false };

	//// AUTOMATIC OR SEMI FIRE ////

	/// @brief will this gun fire automatically or semi-automatic.
	bool b_automatic_{ false };

	/// @brief 
	bool b_automatic_replay_{ true };

	/// @brief how fast our gun will shoot, the smaller the numer the faster the fire rate.
	float automatic_fire_rate_{ 0.1f };

private:
	/// @brief 
	/// @return 
	auto get_owner_controller() const -> AController*;

	/// @brief 
	/// @param hit
	/// @param shot_direction
	/// @return 
	auto gun_line_trace(FHitResult& hit, FVector shot_direction) -> bool;

	/// @brief 
	/// @param hit
	/// @param shot_direction
	auto play_fire_effects(FHitResult hit, FVector shot_direction) -> void;

	/// @brief 
	auto fire_weapon() -> void;

	/// @brief 
	auto fire_projectile_weapon() -> void;
};
