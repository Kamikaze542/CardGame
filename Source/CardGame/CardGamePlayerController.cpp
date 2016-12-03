// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "CardGamePlayerController.h"


ACardGamePlayerController::ACardGamePlayerController()
{
	m_MaxMana = 100;
	m_CurrentMana = 0;
}

void ACardGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
	FInputModeGameAndUI iM;
	SetInputMode(iM);
}

unsigned int ACardGamePlayerController::GetMaxMana()
{
	return m_MaxMana;
}

unsigned int ACardGamePlayerController::GetCurrentMana()
{
	return m_CurrentMana;
}

void ACardGamePlayerController::SetCurrentMana(unsigned int mana)
{
	m_CurrentMana = mana;
}
