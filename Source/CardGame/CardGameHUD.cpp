#include "CardGame.h"

#include "CardGameHUD.h"
#include "CardGameHudUI.h"

ACardGameHUD::ACardGameHUD(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
}

void ACardGameHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (GEngine && GEngine->GameViewport)
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;

		SAssignNew(GameHUD, SCardGameHudUI)
			.OwnerHUD(TWeakObjectPtr<ACardGameHUD>(this));

		Viewport->AddViewportWidgetContent(
			SNew(SWeakWidget).PossiblyNullContent(GameHUD.ToSharedRef())
		);
	}
}