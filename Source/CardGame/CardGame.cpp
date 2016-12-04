#include "CardGame.h"
#include "MenuStyles.h" 

 
IMPLEMENT_PRIMARY_GAME_MODULE(FCardGameGameModule, CardGame, "CardGame");

	void FCardGameGameModule::StartupModule()
	{
		//Hot reload hack
		FSlateStyleRegistry::UnRegisterSlateStyle(FMenuStyles::GetStyleSetName());
		FMenuStyles::Initialize();
		MyUIResources.Initialize();
	}

	void FCardGameGameModule::ShutdownModule()
	{
		FMenuStyles::Shutdown();
		MyUIResources.Shutdown();
	}

	TSharedPtr<FSlateGameResources> FCardGameGameModule::GetSlateGameResources()
	{
		/*Give caller a pointer to our FSlateGameResources*/
		/*Giving strong pointer, helps gurantee access to resources*/
		return MyUIResources.GetSlateGameResources();
	}



