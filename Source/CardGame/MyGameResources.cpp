#include "CardGame.h"
#include "SlateGameResources.h"
#include "MyGameResources.h"

void SMyUIWidget::Construct(const FArguments& InArgs)
{

	MyUIResources = FModuleManager::GetModuleChecked<FCardGameGameModule>(FName("CardGame")).GetSlateGameResources();
	const FSlateBrush *m_icon = MyUIResources->GetBrush(FName("CreatureCard.jpg"));
	OwnerHUD = InArgs._OwnerHUD;

	

	ChildSlot.VAlign(VAlign_Bottom).HAlign(HAlign_Center)
		[
			SNew(SOverlay)
		+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill)
		[
			SNew(SHorizontalBox).Visibility(EVisibility::Visible)
		+ SHorizontalBox::Slot().HAlign(HAlign_Left).VAlign(VAlign_Bottom)
		[   
			SNew(SImage).Image(m_icon)
		]
	+ SHorizontalBox::Slot().HAlign(HAlign_Left).VAlign(VAlign_Bottom)
		[
			SNew(SImage).Image(m_icon)
		]
	+ SHorizontalBox::Slot().HAlign(HAlign_Left).VAlign(VAlign_Bottom)
		[
			SNew(SImage).Image(m_icon)
		]
	+ SHorizontalBox::Slot().HAlign(HAlign_Left).VAlign(VAlign_Bottom)
		[
			SNew(SImage).Image(m_icon)
		]
		]
		];
}

void FMyUIResources::Initialize()
{
	if (!MyUIResources.IsValid())
	{
		MyUIResources = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*MyUIResources);
	}
}

TSharedPtr<FSlateGameResources> FMyUIResources::GetSlateGameResources()
{
	return MyUIResources;
}

TSharedRef<class FSlateGameResources> FMyUIResources::Create()
{
	return FSlateGameResources::New(FName("MyUIResources"), m_Path, m_Path);
}

/*Unregister resources/styles with Slate, cleanup, free memory*/
void FMyUIResources::Shutdown()
{
	//Unregister *MyUIResources with Slate
	FSlateStyleRegistry::UnRegisterSlateStyle(*MyUIResources);

	//Debugging
	ensure(MyUIResources.IsUnique());

	//Removes reference to resources, decrements refcount, destroys resources if refcount=0
	//Do this to all SharedPtrs on Shutdown() or SomethingSimilar() to avoid memory leak
	MyUIResources.Reset();
}