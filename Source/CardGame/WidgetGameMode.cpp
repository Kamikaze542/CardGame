// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "WidgetGameMode.h"
#include "MainMenuHUD.h"

AWidgetGameMode::AWidgetGameMode(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	HUDClass = ACardGameHUD::StaticClass();
	
}
