// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/SS_Hud_shooter.h"


ASS_Hud_shooter::ASS_Hud_shooter()
{
	// Set path to our muzzle flash particle system.
	static ConstructorHelpers::FObjectFinder<UTexture> cross_hair_texture_container(*cross_hair_path_);
	if (cross_hair_texture_container.Succeeded())
	{
		cross_hair_texture_ = cross_hair_texture_container.Object;
	}
}

auto ASS_Hud_shooter::DrawHUD() -> void
{
	const FVector2D viewport_size   = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());          
	screen_center_ = FVector2D((viewport_size.X / 2), (viewport_size.Y / 2));

	crosshair_location_.X = screen_center_.X - crosshair_half_width_;
	crosshair_location_.Y = screen_center_.Y - crosshair_half_height_;

	this->DrawTexture(cross_hair_texture_,
					  crosshair_location_.X,
					  crosshair_location_.Y,
					  64.f,
					  64.f,
					  0.f,
					  0.f,
					  1.f,
					  1.f);

	Super::DrawHUD();
}
