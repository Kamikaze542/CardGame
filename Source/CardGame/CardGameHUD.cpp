#include "CardGame.h"
#include "MyGameResources.h"
#include "CardGameHUD.h"


ACardGameHUD::ACardGameHUD(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{

}

void ACardGameHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("BUILDING THIS HUD IS WORKING!"));
	GEngine->AddOnScreenDebugMessage(4, 10, FColor::Green, TEXT("AM I A WORKING HUD!?"));
	SAssignNew(MyUIWidget, SMyUIWidget).OwnerHUD(this);

	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MyUIWidget.ToSharedRef()));
	}
}
/*
void ACardGameHUD::BeginPlay()
{

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Create a SMyUIWidget on heap referenced by MyUIWidget pointer member
	SAssignNew(MyUIWidget, SMyUIWidget).OwnerHUD(this);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Pass our viewport a weak reference to our widget, will not increment refcount
	if (GEngine->IsValidLowLevel())
		GEngine->GameViewport->
		AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MyUIWidget.ToSharedRef()));

	if (MyUIWidget.IsValid())
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/////Set widget's properties as visibile (sets child widget's properties recurisvely)
		MyUIWidget->SetVisibility(EVisibility::Visible);
	}
}*/