// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Minion.h"
#include "Spell.generated.h"

UCLASS()
class CARDGAME_API ASpell : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpell();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	bool GetCausesStatusEffect();
	bool GetIsDOT();
	unsigned int GetDamageValue();
	float GetAOERadius();
	bool GetIsTeam1();
	float GetSlowFactor();

	void SetCausesStatusEffect(bool SE);
	void SetIsDOT(bool DOT);
	void SetDamageValue(int Dmg);
	void SetAOERadius(float Size);
	void SetIsTeam1(bool Team1);
	void SetSlowFactor(float SlowFactor);




private:	
	bool m_causesStatusEffect;
	bool m_isDOT;
	unsigned int m_DamageValue;
	float m_AOERadius;
	AMinion* m_CollidingMinion;
	TArray<AMinion*> m_AffectedMinions;
	float m_SlowFactor;


	UPROPERTY(EditAnywhere)
	USphereComponent* m_SphereCollider;

	UPROPERTY(EditAnywhere)
	bool m_IsTeam1;
	


};
