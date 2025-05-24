// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

// Unreal headers
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SS_Player_controller.generated.h"


/**
 *	Player controller for Shooter player in game 
 */
UCLASS()
class SIMPLESHOOTER_API ASS_Player_controller : public APlayerController
{
	GENERATED_BODY()

public:
	/// @brief Sets default values for this actor's properties.
	ASS_Player_controller();

	/// @brief Gets health widget ref.
	/// @return Health widget ref.
	FORCEINLINE auto get_health_widget()  const -> TSharedPtr<class SSS_Widget_health_bar> { return health_widget_ref_; }

	/// @brief Handle win/lose condition.
	/// @param end_game_focus actor to view with camera.
	/// @param b_is_winner    true if this controller is on winning team.
	auto GameHasEnded(class AActor* end_game_focus = nullptr, bool b_is_winner = false) -> void override;

protected:
	/// @brief Called when the game starts or when spawned.
	auto BeginPlay() -> void override;

private:
	/// @brief puts the health progress bar and symbol on screen.
	auto set_up_health_widget() -> void;

	/// @brief prints the win message to player HUD.
	auto set_up_win_widget() -> void;

	/// @brief prints the losing message to player HUD.
	auto set_up_lose_widget() -> void;

	/* --------------------- REFERENCES --------------------- */

	/// @brief reference to player character so we can update the health widget percentage.
	class ASS_Player_character* player_character_ref_;
	
	/* ------------------ TIMER PROPERTIES ------------------ */

	/// @brief Timer allowing us to trigger game retart based on elapsed time.
	FTimerHandle restart_timer_;

	/// @brief time to count down from before game restarts.
	float restart_delay_{ 5.f };

	/* ----------------------- WIDGETS ---------------------- */

	//// HEALTH ////

	/// @brief ptr to widget that holds the HUD overlay widget.
	TSharedPtr<SWidget> health_widget_container_;

	/// @brief HUD Overlay for Health and Weapons.
	TSharedPtr<class SSS_Widget_health_bar> health_widget_ref_;

	/// @brief params for the health widget so we can make the FSlateBrush.
	UTexture2D* health_bar_texture_;

	/// @brief params for the health widget so we can make the FSlateBrush.
	UTexture2D* health_icon_texture_;

	//// GAME WIN ////

	/// @brief ptr to widget that holds the win game widget.
	TSharedPtr<SWidget> win_game_widget_container_;

	/// @brief Text widget that appears if character wins game.
	TSharedPtr<class SSS_Widget_win_screen> win_screen_ref_;

	//// GAME LOSE ////

	/// @brief ptr to widget that holds the lose game widget.
	TSharedPtr<SWidget> lose_game_widget_container_;

	/// @brief Text widget that appears if character loses game.
	TSharedPtr<class SSS_Widget_lose_screen> lose_screen_ref_;

	/* ------------------- PATHS TO WIDGETS ------------------ */

	//// HEALTH ////
	
	/// @brief path to health bar full texture.
	const FString health_bar_full_path_{ "Texture2D'/Game/AssetPacks/ShooterGame/HUD/HeathBar_Full.HeathBar_Full'" };

	/// @brief path to health icon full texture.
	const FString health_icon_path_{ "Texture2D'/Game/AssetPacks/ShooterGame/HUD/HUD_Health_Icon.HUD_Health_Icon'" };
};
