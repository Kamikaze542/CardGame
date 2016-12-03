// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "Minion.h"
#include "MinionCard.h"


AMinionCard::AMinionCard()
{
	PrimaryActorTick.bCanEverTick = true;
	Luck = 1;
	Belief = 1;
	BeliefAcuity = 2.5f;
}

void AMinionCard::BeginPlay()
{
	Super::BeginPlay();

}

void AMinionCard::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AMinionCard::Play()
{
	if (Super::IsPlayable())
	{
		AMinion* minion = (AMinion*)GetWorld()->SpawnActor<AMinion>();
		minion->SetLuck(Luck);
		minion->SetBelief(Belief);
		minion->SetBeliefAcuity(BeliefAcuity);
	}
}

