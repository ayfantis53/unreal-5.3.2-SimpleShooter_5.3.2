// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

// Unreal headers
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"


/**
 * 	Slate widget that is design and function of lose game text 
 */
class SIMPLESHOOTER_API SSS_Widget_lose_screen : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSS_Widget_lose_screen)
	{}
	SLATE_END_ARGS()

	/// @brief struct that contains the parameters passed to the widget during its construction.
	auto Construct(const FArguments& in_args) -> void;

private:
	/* ------------------- TEXT PROPERTIES ------------------ */

	/// @brief Text pointer for player losing.
	TSharedPtr<STextBlock> lose_text_;

	/// @brief Text pointer level will restart.
	TSharedPtr<STextBlock> restart_text_;

	/// @brief Value for text lost game text.
	FString lose_game_text_{ "You LOST!" };

	/// @brief Value for text level restart text.
	FString level_restart_text_{ "Level will restart in 5 seconds..." };

	/// @brief Shadow offset.
	FVector2D text_shadow_offset_{ FVector2D(1.f, 1.f) };

	/// @brief Color to set the lose text.
	FLinearColor lose_text_color_{ FLinearColor::Red };

	/// @brief Color to set the lose text shadow.
	FLinearColor lose_text_shadow_color_{ FLinearColor(0, 0, 0, 1) };

	/// @brief needed to set the widget text to Roboto.
	inline const static FString roboto_path_{ "Slate/Fonts/Roboto-Bold.ttf" };
};
