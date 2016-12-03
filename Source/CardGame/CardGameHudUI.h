#pragma once

#include "Slate.h"

// Lays out and controls the Tutorial HUD UI.

class SCardGameHudUI : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SCardGameHudUI)
		: _OwnerHUD()
	{
	}

	SLATE_ARGUMENT(TWeakObjectPtr<class ACardGameHUD>, OwnerHUD);

	SLATE_END_ARGS()

public:
	/**
	* Constructs and lays out the Tutorial HUD UI Widget.
	*
	* \args Arguments structure that contains widget-specific setup information.
	**/
	void Construct(const FArguments& args);

private:
	/**
	* Stores a weak reference to the HUD owning this widget.
	**/
	TWeakObjectPtr<class ACardGameHUD> OwnerHUD;

	/**
	* A reference to the Slate Style used for this HUD's widgets.
	**/
	const struct FGlobalStyle* HUDStyle;
};