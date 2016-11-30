// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Minion.generated.h"

UCLASS()
class CARDGAME_API AMinion : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMinion();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	unsigned int GetLuck();
	unsigned int GetBelief();

	void SetLuck(unsigned int Luck);
	void SetBelief(unsigned int Belief);

private:
	unsigned int m_Luck;
	unsigned int m_Belief;
	
	
};
