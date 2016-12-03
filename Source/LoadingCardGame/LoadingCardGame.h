#ifndef __LOADINGCARDGAME_H__
#define __LOADINGCARDGAME_H__

#include "ModuleInterface.h"


/** Module interface for this game's loading screens */
class ILoadingCardGameModule : public IModuleInterface
{
public:
	/** Kicks off the loading screen for in game loading (not startup) */
	virtual void StartInGameLoadingScreen() = 0;
};

#endif