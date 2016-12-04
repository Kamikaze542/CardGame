// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "CardGameGameModeBase.h"



void ACardGameGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	AActor* spawnLocation;
	spawnLocation = ChoosePlayerStart(NewPlayer);
	GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Red, FString::Printf(TEXT("GameModeSpawnTransformInfo: %s, %s"), *spawnLocation->GetActorTransform().GetLocation().ToString(), *spawnLocation->GetActorTransform().GetRotation().Rotator().ToString()));
	NewPlayer->SetInitialLocationAndRotation(spawnLocation->GetActorTransform().GetLocation(), spawnLocation->GetActorTransform().GetRotation().Rotator());
	NewPlayer->ClientSetRotation(spawnLocation->GetActorTransform().GetRotation().Rotator());
}
