// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "Spell.h"
#include "SpellCard.h"

ASpellCard::ASpellCard()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASpellCard::BeginPlay()
{
	Super::BeginPlay();
}

void ASpellCard::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ASpellCard::Play()
{
	if (Super::IsPlayable())
	{
		ASpell* spell = (ASpell*)GetWorld()->SpawnActor<ASpell>();
		spell->SetDamageValue(DamageValue);
		spell->SetAOESize(AOESize);
		switch (DamageType)
		{
		case EDamageType::fire:
			spell->SetCausesStatusEffect(false);
			spell->SetIsDOT(false);
			break;
		case EDamageType::ice:
			spell->SetCausesStatusEffect(true);
			spell->SetIsDOT(false);
			break;
		case EDamageType::poison:
			spell->SetCausesStatusEffect(false);
			spell->SetIsDOT(true);
			break;
		}
	}
}


