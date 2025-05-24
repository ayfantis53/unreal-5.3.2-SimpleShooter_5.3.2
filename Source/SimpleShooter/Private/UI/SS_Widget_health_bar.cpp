// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/SS_Widget_health_bar.h"

// Unreal includes
#include "SlateBasics.h"
#include "SlateOptMacros.h"
#include "Widgets/Layout/SConstraintCanvas.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
auto SSS_Widget_health_bar::Construct(const FArguments& in_args) -> void
{
	health_bar_brush_       = FSlateImageBrush(in_args._health_bar,
											   health_bar_size_,
											   health_bar_tint_green_);

	health_bar_empty_brush_ = FSlateImageBrush(in_args._health_bar,
											   health_bar_size_,
											   health_bar_tint_red_);

	icon_brush_             = FSlateImageBrush(in_args._health_icon,
											   health_icon_size,
											   health_icon_green_);

	ChildSlot
		[
			// Populate the widget.
			SNew(SCanvas)
				+ SCanvas::Slot()
				.Position(FVector2D(797.f, 10.f))
				.Size(health_bar_size_)
				[
					// Progress Bar.
					SAssignNew(progress_bar_ref, SProgressBar)
						.BarFillType(EProgressBarFillType::LeftToRight)
						.BarFillStyle(EProgressBarFillStyle::Scale)
						.Percent(percent_full_)
						.FillColorAndOpacity(fill_color_green_)
						.BackgroundImage(&health_bar_empty_brush_)
						.FillImage(&health_bar_brush_)
						.BorderPadding(FVector2D(1, 1))
				]
				+ SCanvas::Slot()
				.Position(FVector2D(857.f, 50.f))
				.Size(health_icon_size)
				[
					// Health Icon.
					SNew(SImage)
						.Image(&icon_brush_)
						.ColorAndOpacity(health_icon_green_)
				]
		];
		
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

