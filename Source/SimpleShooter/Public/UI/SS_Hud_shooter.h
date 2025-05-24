// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

// Unreal headers
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SS_Hud_shooter.generated.h"


/**
 *	Main Players HUD for screen
 */
UCLASS()
class SIMPLESHOOTER_API ASS_Hud_shooter : public AHUD
{
	GENERATED_BODY()

	/// @brief Sets hud default properties.
	ASS_Hud_shooter();
	
protected:
	/// @brief The Main Draw loop for the hud. Gets called before any messaging.
	auto DrawHUD() -> void override;

private:
	/// @brief
	FVector2D screen_center_;

	/* -------------------- CROSS-HAIRS --------------------- */

	/// @brief
	UPROPERTY()
	UTexture* cross_hair_texture_;

	/// @brief
	FVector2D crosshair_location_;

	/// @brief
	float crosshair_half_height_{ 30.f };

	/// @brief
	float crosshair_half_width_{ 30.f };

	//// PATH TO CROSSHAIRS ////
	
	/// @brief
	FString cross_hair_path_{ "Texture2D'/Game/AssetPacks/ShooterGame/HUD/Cross_Q_9.Cross_Q_9'" };
};
