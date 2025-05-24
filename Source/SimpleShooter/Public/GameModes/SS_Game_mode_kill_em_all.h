// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

// Unreal headers
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SS_Game_mode_kill_em_all.generated.h"


/**
 *	Game Mode handles what happens when all enemies die or player dies
 */
UCLASS()
class SIMPLESHOOTER_API ASS_Game_mode_kill_em_all : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	ASS_Game_mode_kill_em_all();

	/// @brief
	/// @param pawn_ref
	auto pawn_killed(APawn* pawn_ref) -> void;

private:
	/// @brief
	/// @param b_is_player_winner
	auto end_game(bool b_is_player_winner) -> void;
};
