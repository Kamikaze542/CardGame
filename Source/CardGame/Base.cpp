// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "Base.h"


// Sets default values
ABase::ABase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_hitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	m_hitBox->InitBoxExtent(FVector(200.0f, 700.0f, 100.0f));
	m_maxHealth = 1000.0f;
	m_currentHealth = m_maxHealth;
}

// Called when the game starts or when spawned
void ABase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

float ABase::GetCurrentHealth()
{
	return m_currentHealth;
}

bool ABase::GetTeam1()
{
	return m_team1;
}

void ABase::SetCurrentHealth(float health)
{
	m_currentHealth = health;
}