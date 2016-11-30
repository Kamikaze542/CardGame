// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseCard.h"
#include "MinionCard.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAME_API AMinionCard : public ABaseCard
{
	GENERATED_BODY()
	
public:
	AMinionCard();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void Play();

	UPROPERTY(EditAnywhere)
	unsigned int Luck;

	UPROPERTY(editanywhere)
	unsigned int Belief;
};
