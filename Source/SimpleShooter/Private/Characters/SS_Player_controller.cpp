// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/SS_Player_controller.h"
#include "UI/SS_Widget_health_bar.h"
#include "UI/SS_Widget_win_screen.h"
#include "UI/SS_Widget_lose_screen.h"

// Unreal includes
#include "SlateBasics.h"
#include "Kismet/GameplayStatics.h"


ASS_Player_controller::ASS_Player_controller()
{
	static  ConstructorHelpers::FObjectFinder<UTexture2D> health_bar_container(*health_bar_full_path_);
	if (health_bar_container.Succeeded())
	{
		health_bar_texture_ = health_bar_container.Object;
	}
	static  ConstructorHelpers::FObjectFinder<UTexture2D> health_icon_container(*health_icon_path_);
	if (health_icon_container.Succeeded())
	{
		health_icon_texture_ = health_icon_container.Object;
	}
}

// Called when the game starts or when spawned
auto ASS_Player_controller::BeginPlay() -> void
{
	Super::BeginPlay();

	set_up_health_widget();
}

// Handle win/lose condition
auto ASS_Player_controller::GameHasEnded(AActor* end_game_focus, bool b_is_winner) -> void
{
	Super::GameHasEnded(end_game_focus, b_is_winner);

	// What to do if we win or lose
	if (b_is_winner)
	{
		set_up_win_widget();
	}
	else
	{
		// Make widget for lose screen condition
		set_up_lose_widget();

		// Restart Game
		GetWorldTimerManager().SetTimer(restart_timer_, this, &APlayerController::RestartLevel, restart_delay_);
	}
}

auto ASS_Player_controller::set_up_health_widget() -> void
{
	// Draw Widget.
	if (GEngine && GEngine->GameViewport)
	{
		// Get viewport.
		UGameViewportClient* view_port = GEngine->GameViewport;

		// Initialize widget.
		health_widget_ref_ = SNew(SSS_Widget_health_bar).health_bar(health_bar_texture_).health_icon(health_icon_texture_);
		view_port->AddViewportWidgetContent(SAssignNew(health_widget_container_, SWeakWidget).PossiblyNullContent(health_widget_ref_));

		// Make widget seen on screen.
		health_widget_ref_->SetVisibility(EVisibility::Visible);
	}
}


auto ASS_Player_controller::set_up_win_widget() -> void
{
	// Draw Widget.
	if (GEngine && GEngine->GameViewport)
	{
		// Get viewport.
		UGameViewportClient* view_port = GEngine->GameViewport;

		// Initialize widget.
		win_screen_ref_ = SNew(SSS_Widget_win_screen);
		view_port->AddViewportWidgetContent(SAssignNew(win_game_widget_container_, SWeakWidget).PossiblyNullContent(win_screen_ref_));

		// Make widget seen on screen.
		win_screen_ref_->SetVisibility(EVisibility::Visible);
	}
}

auto ASS_Player_controller::set_up_lose_widget() -> void
{
	// Draw Widget.
	if (GEngine && GEngine->GameViewport)
	{
		// Get viewport.
		UGameViewportClient* view_port = GEngine->GameViewport;

		// Initialize widget.
		lose_screen_ref_ = SNew(SSS_Widget_lose_screen);
		view_port->AddViewportWidgetContent(SAssignNew(lose_game_widget_container_, SWeakWidget).PossiblyNullContent(lose_screen_ref_));

		// Make widget seen on screen.
		lose_screen_ref_->SetVisibility(EVisibility::Visible);
	}
}
