// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "Spell.h"


// Sets default values
ASpell::ASpell()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpell::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool ASpell::GetCausesStatusEffect()
{
	return m_causesStatusEffect;
}

bool ASpell::GetIsDOT()
{
	return m_isDOT;
}

unsigned int ASpell::GetDamageValue()
{
	return m_DamageValue;
}

FVector ASpell::GetAOESize()
{
	return m_AOESize;
}

void ASpell::SetCausesStatusEffect(bool SE)
{
	m_causesStatusEffect = SE;
}

void ASpell::SetIsDOT(bool DOT)
{
	m_isDOT = DOT;
}

void ASpell::SetDamageValue(int Dmg)
{
	m_DamageValue = Dmg;
}

void ASpell::SetAOESize(FVector Size)
{
	m_AOESize = Size;
}
