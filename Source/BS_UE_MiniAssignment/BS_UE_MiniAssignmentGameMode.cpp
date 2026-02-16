// Copyright Epic Games, Inc. All Rights Reserved.

#include "BS_UE_MiniAssignmentGameMode.h"
#include "BS_UE_MiniAssignmentCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABS_UE_MiniAssignmentGameMode::ABS_UE_MiniAssignmentGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
