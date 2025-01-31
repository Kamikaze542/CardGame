// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "CardGameGameModeBase.generated.h"

/**
 * 
 */


UCLASS()
class CARDGAME_API ACardGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
	void SpawnCard(UClass* card, FVector loc, bool isPlayer1, int werbad);
private:
	TArray<APlayerController*> PlayerList;
};
