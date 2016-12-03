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
	void SetCurrentMana(unsigned int mana);
	
private:
	unsigned int m_MaxMana;
	unsigned int m_CurrentMana;
};
