// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "BaseCard.h"


// Sets default values
ABaseCard::ABaseCard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ABaseCard::BeginPlay()
{
	Super::BeginPlay();
	playerController = Cast<ACardGamePlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	m_team1 = playerController->GetP1();
}

// Called every frame
void ABaseCard::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool ABaseCard::IsPlayable()
{
	if (playerController->GetCurrentMana() < m_ManaCost)
	{
		return false;
	}
	else
	{
		return true;
	}
}

unsigned int ABaseCard::GetManaCost()
{
	return m_ManaCost;
}

FString ABaseCard::GetCardName()
{
	return m_CardName;
}



