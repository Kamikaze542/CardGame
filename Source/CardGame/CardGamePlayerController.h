// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "CardGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAME_API ACardGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACardGamePlayerController();

	virtual void BeginPlay() override;

	unsigned int GetMaxMana();
	unsigned int GetCurrentMana();
	bool GetP1();
	void SetCurrentMana(unsigned int mana);
	void SetP1(bool player1);
	
private:
	unsigned int m_MaxMana;
	unsigned int m_CurrentMana;
	bool m_p1;
};
