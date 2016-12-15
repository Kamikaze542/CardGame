// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "RaycastTarget.h"
#include "Engine.h"
#include "CardGameGameModeBase.h"
#include "Minion.h"
#include "GameFramework/PlayerController.h"
#include "CardGamePlayerController.generated.h"


/**
 * 
 */
 //Enum of every cards
UENUM()
enum class ECardName : uint8
{
	//Minion cards:
	SMALL_MINION, MEDIUM_MINION, LARGE_MINION,
	//Spell Cards:
	FIRE_SPELL, POISON_SPELL, ICE_SPELL,

	//
	COUNT
};

UCLASS()
class CARDGAME_API ACardGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACardGamePlayerController();

	virtual void BeginPlay() override;

	unsigned int GetMaxMana();
	unsigned int GetCurrentMana();
	AMinion* add_Minion;
	UClass* m_sMinion;
	UClass* m_mMinion;
	UClass* m_lMinion;
	UClass* m_fSpell;
	UClass* m_pSpell;
	UClass* m_iSpell;

	
	void PlayCard(ECardName cardPlayed, FVector location);

	UFUNCTION(Server, Reliable, WithValidation)
	void PlayCardNetwork(ECardName cardPlayed, FVector location);

	UFUNCTION(BlueprintCallable, Category = "Card")
	void CardClicked(int cardnum);

	void SetupInputComponent();
	
	bool GetP1();
	void SetCurrentMana(unsigned int mana);
	void SetP1(bool player1);
	
private:
	unsigned int m_MaxMana;
	unsigned int m_CurrentMana;
	void PerformRaycast();
	bool m_p1;
	ACardGameGameModeBase* gm;
};
