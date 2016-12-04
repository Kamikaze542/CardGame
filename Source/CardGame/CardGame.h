// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "UnrealNetwork.h"
#include "Online.h"
#include "MyGameResources.h"

class FCardGameGameModule : public FDefaultGameModuleImpl
{
public:
	void StartupModule();
	void ShutdownModule();
	TSharedPtr<FSlateGameResources> GetSlateGameResources();
protected:
	FMyUIResources MyUIResources;
};
