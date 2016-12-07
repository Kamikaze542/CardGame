// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "CardGamePlayerController.h"
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
