#pragma once

#include "GameFramework/HUD.h"
#include "CardGameHUD.generated.h"

UCLASS()
class ACardGameHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

		virtual void PostInitializeComponents() override;

protected:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Reference to SCompoundWidget
	TSharedPtr<class SMyUIWidget> MyUIWidget;
};