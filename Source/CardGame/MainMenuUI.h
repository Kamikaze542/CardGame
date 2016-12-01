
#pragma once

#include "SlateBasics.h"

class CARDGAME_API SMainMenuUI : public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SMainMenuUI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MainMenuHUD)
		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs);

	/**
	* Click handler for the Play Game! button – Calls MenuHUD’s PlayGameClicked() event.
	*/
	FReply PlayGameClicked();
	/**
	* Click handler for the Quit Game button – Calls MenuHUD’s QuitGameClicked() event.
	*/
	FReply QuitGameClicked();

	TWeakObjectPtr<class AMainMenuHUD> MainMenuHUD;

	const struct FGlobalStyle* MenuStyle;

};
