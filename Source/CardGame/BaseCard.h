// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CardGamePlayerController.h"
#include "BaseCard.generated.h"

UCLASS()
class CARDGAME_API ABaseCard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseCard();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	bool IsPlayable();

	ACardGamePlayerController* playerController;

	unsigned int GetManaCost();
	FString GetCardName();

protected:
	unsigned int m_ManaCost;
	FString m_CardName;
	
};
