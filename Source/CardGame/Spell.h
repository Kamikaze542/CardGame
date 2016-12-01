// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Spell.generated.h"

UCLASS()
class CARDGAME_API ASpell : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpell();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	bool GetCausesStatusEffect();
	bool GetIsDOT();
	unsigned int GetDamageValue();
	FVector GetAOESize();

	void SetCausesStatusEffect(bool SE);
	void SetIsDOT(bool DOT);
	void SetDamageValue(int Dmg);
	void SetAOESize(FVector Size);

private:	
	bool m_causesStatusEffect;
	bool m_isDOT;
	unsigned int m_DamageValue;
	FVector m_AOESize;
};
