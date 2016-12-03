#include "CardGame.h"

#include "CardGameHUD.h"
#include "CardGameHudUI.h"

#include "GlobalMenuStyle.h"
#include "MenuStyles.h"

void SCardGameHudUI::Construct(const FArguments& args)
{
	OwnerHUD = args._OwnerHUD;

	HUDStyle = &FMenuStyles::Get().GetWidgetStyle<FGlobalStyle>("Global");

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Top)
		[
			SNew(STextBlock)
			.TextStyle(&HUDStyle->MenuTitleStyle)
		.Text(FText::FromString("SCORE: 0"))
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		[
			SNew(STextBlock)
			.TextStyle(&HUDStyle->MenuTitleStyle)
		.Text(FText::FromString("HEALTH: 100"))
		]
		];
}