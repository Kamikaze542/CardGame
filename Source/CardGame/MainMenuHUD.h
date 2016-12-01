// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
// MainMenuHUD.h – Provides an implementation of the HUD that will embed the Main Menu Slate UI.

#pragma once

#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

/**
* Provides an implementation of the game’s Main Menu HUD, which will embed and respond to events triggered
* within SMainMenuUI.
*/
UCLASS()
class CARDGAME_API AMainMenuHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

		virtual void PostInitializeComponents() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
		void PlayGameClicked();

	UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
		void QuitGameClicked();

	TSharedPtr<class SMainMenuUI> MainMenuUI;
};