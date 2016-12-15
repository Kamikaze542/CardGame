// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Base.generated.h"

UCLASS()
class CARDGAME_API ABase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	float GetCurrentHealth();
	bool GetTeam1();

	void SetCurrentHealth(float health);


private:
	float m_maxHealth;
	float m_currentHealth;

	UPROPERTY(EditAnywhere)
	bool m_team1;

	UPROPERTY(editAnywhere)
	UBoxComponent* m_hitBox;
};
