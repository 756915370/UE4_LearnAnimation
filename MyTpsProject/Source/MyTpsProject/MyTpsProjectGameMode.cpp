// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyTpsProjectGameMode.h"
#include "MyTpsProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyTpsProjectGameMode::AMyTpsProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
