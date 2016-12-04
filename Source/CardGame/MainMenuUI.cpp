
#include "CardGame.h"
#include "MainMenuUI.h"
#include "GlobalMenuStyle.h" 
#include "MenuStyles.h" 
#include "SlateGameResources.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuUI::Construct(const FArguments& args)
{
	//Getting reference to game resources from game module
	static const FName module_name = "CardGame";
	//FSlateGameResources MyUIResources = FModuleManager::GetModuleChecked<FCardGameGameModule>(module_name).GetSlateGameResources();
	//FSlateImageBrush *m_icon = MyUIResources->GetBrush(FName("/spells/spell_heal"));


	MainMenuHUD = args._MainMenuHUD;
	MenuStyle = &FMenuStyles::Get().GetWidgetStyle<FGlobalStyle>("Global");
	//HUDStyle = &FStrategyStyle::Get().GetWidgetStyle<FStrategyHUDStyle>("DefaultStrategyHUDStyle");
	
	//TODO:  Need to change this path to a real one
	static const FName CardFileName(TEXT("/Game/UI/Images/CardCreature.jpg"));
	
	//since we are not using game styles here, just load one image
	

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(STextBlock)
			.TextStyle(&MenuStyle->MenuTitleStyle)
		.Text(FText::FromString("Main Menu"))
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SImage)
			//.Image(m_icon)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		[
			SNew(SButton)
			.ButtonStyle(&MenuStyle->MenuButtonStyle)
		.TextStyle(&MenuStyle->MenuButtonTextStyle)
		.Text(FText::FromString("Play Game!"))
		.OnClicked(this, &SMainMenuUI::PlayGameClicked)
		]
	+ SVerticalBox::Slot()
		[
			SNew(SButton)
			.ButtonStyle(&MenuStyle->MenuButtonStyle)
		.TextStyle(&MenuStyle->MenuButtonTextStyle)
		.Text(FText::FromString("Quit Game"))
		.OnClicked(this, &SMainMenuUI::QuitGameClicked)
		]
		]
		];
		

	/*
	ChildSlot
	[
	SNew(SOverlay)
	+ SOverlay::Slot()
	.HAlign(HAlign_Center)
	.VAlign(VAlign_Top)
	[
	SNew(STextBlock)
	.ColorAndOpacity(FLinearColor::White)
	.ShadowColorAndOpacity(FLinearColor::Black)
	.ShadowOffset(FIntPoint(-1, 1))
	.Font(FSlateFontInfo("Arial", 26))
	.Text(FText::FromString("Main Menu"))
	]
	+ SOverlay::Slot()
	.HAlign(HAlign_Right)
	.VAlign(VAlign_Bottom)
	[
	SNew(SVerticalBox)
	+ SVerticalBox::Slot()
	[
	SNew(SButton)
	.Text(FText::FromString("Play Game!"))
	.OnClicked(this, &SMainMenuUI::PlayGameClicked)
	]
	+ SVerticalBox::Slot()
	[
	SNew(SButton)
	.Text(FText::FromString("Quit Game"))
	.OnClicked(this, &SMainMenuUI::QuitGameClicked)
	]
	]
	];
	*/

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SMainMenuUI::PlayGameClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("PlayGameClicked"));
	}
	//MainMenuHUD->PlayGameClicked();
	return FReply::Handled();
}
FReply SMainMenuUI::QuitGameClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("QuitGameClicked"));
	}
	//MenuHUD->QuitGameClicked();
	return FReply::Handled();
}


