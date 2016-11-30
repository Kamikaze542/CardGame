// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "Minion.h"


// Sets default values
AMinion::AMinion()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_Luck = 1;
	m_Belief = 1;
}


// Called when the game starts or when spawned
void AMinion::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMinion::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

unsigned int AMinion::GetLuck()
{
	return m_Luck;
}

unsigned int AMinion::GetBelief()
{
	return m_Belief;
}

void AMinion::SetLuck(unsigned int Luck)
{
	m_Luck = Luck;
}

void AMinion::SetBelief(unsigned int Belief)
{
	m_Belief = Belief;
}



