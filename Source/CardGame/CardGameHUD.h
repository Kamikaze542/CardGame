// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
// TutorialGameHUD.h - Provides an implementation of the HUD that will embed the Tutorial Game UI.

#pragma once

#include "GameFramework/HUD.h"

#include "CardGameHUD.generated.h"

/**
* Provides an implementation of the game's in-game HUD, which will display the player's current health and score.
**/
UCLASS()
class ACardGameHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

public:
	/**
	* Initializes the Slate UI and adds it as a widget to the game viewport.
	**/
	virtual void PostInitializeComponents() override;

private:
	/**
	* Reference to the Game HUD UI.
	**/
	TSharedPtr<class SCardGameHudUI> GameHUD;
};