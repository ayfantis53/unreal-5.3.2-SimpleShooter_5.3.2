// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/SS_Shooter_anim_instance.h"
#include "Characters/SS_Shooter_character.h"

// Unreal includes
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"


auto USS_Shooter_anim_instance::NativeInitializeAnimation() -> void
{
	shooter_character_ref_ = Cast<ASS_Shooter_character>(TryGetPawnOwner());
}

auto USS_Shooter_anim_instance::update_animation_properties(float delta_time) -> void
{
	if (shooter_character_ref_ == nullptr)
	{
		shooter_character_ref_ = Cast<ASS_Shooter_character>(TryGetPawnOwner());
	}
	if (shooter_character_ref_)
	{
		FVector velocity{ shooter_character_ref_->GetVelocity() };

		velocity.Z	 = 0;
		speed_		 = velocity.Size();
		b_is_in_air_ = shooter_character_ref_->GetCharacterMovement()->IsFalling();

		if (shooter_character_ref_->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f)
		{
			b_is_accelerating_ = true;
		}
		else
		{
			b_is_accelerating_ = false;
		}

		FRotator aim_rotation	   = shooter_character_ref_->GetBaseAimRotation();
		FRotator movement_rotation = UKismetMathLibrary::MakeRotFromX(shooter_character_ref_->GetVelocity());
		movement_offset_yaw_	   = UKismetMathLibrary::NormalizedDeltaRotator(movement_rotation, aim_rotation).Yaw;

		if (shooter_character_ref_->GetVelocity().Size() > 0.f)
		{
			last_movement_offset_yaw_ = movement_offset_yaw_;
		}

		b_aiming_ = shooter_character_ref_->get_aiming();
		b_is_dead_ = shooter_character_ref_->get_is_dead();
	}

	turn_in_place();
	lean(delta_time);
}

auto USS_Shooter_anim_instance::lean(float delta_time) -> void
{
	if (shooter_character_ref_ == nullptr)
	{
		return;
	}

	character_rotation_last_frame_ = character_rotation_;
	character_rotation_            = shooter_character_ref_->GetActorRotation();

	FRotator delta(UKismetMathLibrary::NormalizedDeltaRotator(character_rotation_, character_rotation_last_frame_));

	const float target{ static_cast<float>(delta.Yaw) / delta_time };
	const float interp{ FMath::FInterpTo(yaw_delta_, target, delta_time, 0.6f) };

	yaw_delta_ = FMath::Clamp(interp, -90.f, 90.f);
}

auto USS_Shooter_anim_instance::turn_in_place() -> void
{
	if (shooter_character_ref_ == nullptr)
	{
		return;
	}

	pitch_= shooter_character_ref_->GetBaseAimRotation().Pitch;

	if (speed_ > 0 || b_is_in_air_)
	{
		root_yaw_offset_			  = 0.f;
		tip_character_yaw_			  = shooter_character_ref_->GetActorRotation().Yaw;
		tip_character_yaw_last_frame_ = tip_character_yaw_;
		rotation_curve_last_frame_	  = 0.f;
		rotation_curve_				  = 0.f;

	}
	else
	{
		tip_character_yaw_last_frame_ = tip_character_yaw_;
		tip_character_yaw_			  = shooter_character_ref_->GetActorRotation().Yaw;
		const float tip_yaw_delta{ tip_character_yaw_ - tip_character_yaw_last_frame_ };

		// Clamp value from -180 to 180.
		root_yaw_offset_ = UKismetMathLibrary::NormalizeAxis(root_yaw_offset_ - tip_yaw_delta);

		const float turning{ GetCurveValue(TEXT("DistanceCurve")) };
		if (turning > 0)
		{
			b_turning_in_place_			= true;
			rotation_curve_last_frame_  = rotation_curve_;
			rotation_curve_				= GetCurveValue(TEXT("mask_geo"));
			const float delta_rotation{ rotation_curve_ - rotation_curve_last_frame_ };

			// root_yaw_offset > 0 -> turn left, root_yaw_offset < 0 -> turn right.
			root_yaw_offset_ > 0 ? root_yaw_offset_ -= delta_rotation : root_yaw_offset_ += delta_rotation;

			const float abs_root_yaw_offset{ FMath::Abs(root_yaw_offset_) };
			if (abs_root_yaw_offset > 90.f)
			{
				const float yaw_excess{ abs_root_yaw_offset - 90.f };
				root_yaw_offset_ > 0 ? root_yaw_offset_ -= yaw_excess : root_yaw_offset_ += yaw_excess;
			}
		}
		else
		{
			b_turning_in_place_ = false;
		}
	}

	if (b_is_accelerating_ && rotation_curve_ > 0)
	{
		full_body_ = true;
	}
	else
	{
		full_body_ = false;
	}
}
