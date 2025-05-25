// *************************************************************************** //
// ******************** Unreal Engine version 5.3.2 ************************** //
// Simple Shooter ************************************************************ //
//             																   //
// Developed by Andrew Yfantis. 											   //
// https://github.com/ayfantis53 											   //
//             																   //
// 2025 																	   //
// *************************************************************************** //
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
