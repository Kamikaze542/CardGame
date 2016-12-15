// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "CardGamePlayerController.h"
#include "Minion.h"
#include "Spell.h"
#include "CardGameGameModeBase.h"



void ACardGameGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	AActor* spawnLocation;
	//spawnLocation = ChoosePlayerStart(NewPlayer);
	//FString aString = "Astring";
	PlayerList.Add(NewPlayer);
	GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Green, FString::Printf(TEXT("NumPlayers: %d"), PlayerList.Num()));
	spawnLocation = (PlayerList.Num() == 1) ? FindPlayerStart(NewPlayer, "Player1") : FindPlayerStart(NewPlayer, "Player2");
	GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Green, FString::Printf(TEXT("NumPlayers: %d"), PlayerList.Num()));
	GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Red, FString::Printf(TEXT("GameModeSpawnTransformInfo: %s, %s"), *spawnLocation->GetActorTransform().GetLocation().ToString(), *spawnLocation->GetActorTransform().GetRotation().Rotator().ToString()));
	NewPlayer->SetInitialLocationAndRotation(spawnLocation->GetActorTransform().GetLocation(), spawnLocation->GetActorTransform().GetRotation().Rotator());
	NewPlayer->ClientSetRotation(spawnLocation->GetActorTransform().GetRotation().Rotator());
	
	ACardGamePlayerController* pcRef = (ACardGamePlayerController*)NewPlayer;
	//Initialize setup for players.
	//pcRef->SetupInputComponent();


	if (spawnLocation->ActorHasTag("Player1"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Blue, FString::Printf(TEXT("Player1")));
		pcRef->SetP1(true);
	}
	else if (spawnLocation->ActorHasTag("Player2"))
	{
		pcRef->SetP1(false);
		GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Blue, FString::Printf(TEXT("Player2")));
	}
}

void ACardGameGameModeBase::SpawnCard(UClass* card, FVector loc, bool isPlayer1)
{
	FRotator r = isPlayer1 ? FRotator(0.f, 180.f, 0.f) : FRotator(0.f, 0.f, 0.f);
	AMinion* itemBase = GetWorld()->SpawnActor<AMinion>(card, loc, r);

	
	itemBase->SetLuck(10);
	itemBase->SetBelief(100);
	itemBase->SetBeliefAcuity(2.5f);
	itemBase->SetTeam1(isPlayer1);
	//itemBase->bSimGravityDisabled = false;
	//itemBase->GetCapsuleComponent()->SetSimulatePhysics(true);
	GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Red, FString::Printf(TEXT("LOL")));
}
