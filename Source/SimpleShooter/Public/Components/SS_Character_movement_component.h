// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

// Unreal headers
#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SS_Character_movement_component.generated.h"


/**
 *	Movement component so character will move when we input our controls
 */
UCLASS()
class SIMPLESHOOTER_API USS_Character_movement_component : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	/// @brief Sets default values for this character's properties.
	USS_Character_movement_component();
};
