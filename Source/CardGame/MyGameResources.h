#pragma once

#include "CardGameHUD.h"
#include "Slate.h"
#include "SlateGameResources.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/////Data Structure and Interface for maintaining SlateGameResources on Game to Game basis
class FMyUIResources
{
public:
	FMyUIResources() : m_Path("/Game/UI"), MyUIResources(NULL) { };

	/*Loads resources and registers them with Slate*/
	/*Do this before trying to use resources*/
	void Initialize();

	/*cleanup*/
	/*Do this when shutting down game module*/
	void Shutdown();

	/*reloads textures used by slate renderer*/
	/*Does nothing at the moment*/
	void ReloadTextures();

	/*Give caller a pointer to our FSlateGameResources*/
	TSharedPtr<FSlateGameResources> GetSlateGameResources();

protected:
	/*Creates resources*/
	TSharedRef<class FSlateGameResources> Create();

	/*Defined in Cpp file, change as needed*/
	const FString m_Path;

	/*Poitner to game resources, Initialize() before using*/
	TSharedPtr<FSlateGameResources> MyUIResources;
};

class SMyUIWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMyUIWidget)
	{}

	SLATE_ARGUMENT(TWeakObjectPtr<ACardGameHUD>, OwnerHUD)

		SLATE_END_ARGS()

		//needed for every widget, constructs widget and children.
		void Construct(const FArguments& InArgs);

protected:
	//Pointer to our parent HUD
	/////Consdier making OwnerHUD a more base type for polymorphic HUDs
	TWeakObjectPtr<class ACardGameHUD> OwnerHUD;

	/*Pointer to resources in GameModule*/
	TSharedPtr<FSlateGameResources> MyUIResources;
};