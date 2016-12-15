// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseCard.h"
#include "SpellCard.generated.h"

/**
 * 
 */

UENUM()
enum class EDamageType : uint8
{
	fire, ice, poison
};

UCLASS()
class CARDGAME_API ASpellCard : public ABaseCard
{
	GENERATED_BODY()
	
public:
	ASpellCard();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void Play();



	UPROPERTY(EditAnywhere)
	EDamageType DamageType;

	UPROPERTY(EditAnywhere)
	unsigned int DamageValue;

	UPROPERTY(editanywhere)
	float AOERadius;
};
