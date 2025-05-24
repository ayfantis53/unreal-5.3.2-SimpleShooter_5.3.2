// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

// Unreal headers
#include "CoreMinimal.h"
#include "LegacyCameraShake.h"
#include "SS_Camera_shake_launcher.generated.h"


/**
 *	Camera Shake Effect for when launcher gets fired by player  
 */
UCLASS()
class SIMPLESHOOTER_API USS_Camera_shake_launcher : public ULegacyCameraShake
{
	GENERATED_BODY()
	
public:
	/// @brief Sets default values for this actor's properties.
	USS_Camera_shake_launcher();
};

