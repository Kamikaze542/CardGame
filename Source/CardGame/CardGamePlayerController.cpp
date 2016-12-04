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
	SetIgnoreLookInput(true);
	SetIgnoreMoveInput(true);
	
	GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Red, FString::Printf(TEXT("PCSpawnTransformInfo: %s, %s"), *this->GetActorTransform().GetLocation().ToString(), *this->GetActorTransform().GetRotation().Rotator().ToString()));
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
