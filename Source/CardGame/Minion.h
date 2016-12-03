// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Minion.generated.h"

UCLASS()
class CARDGAME_API AMinion : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMinion();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	unsigned int GetLuck();
	unsigned int GetBelief();
	float GetBeliefAcuity();

	void SetLuck(unsigned int Luck);
	void SetBelief(unsigned int Belief);
	void SetBeliefAcuity(float BA);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(BlueprintReadOnly)
	bool m_inRange;

private:
	unsigned int m_Luck;
	unsigned int m_Belief;
	float m_BeliefAcuity;
	float m_elapsedTime = 0.0f;
	float m_speedHolder;
	USkeletalMesh* skeletal_Mesh;
	AMinion* m_otherMinion;

	UPROPERTY(EditAnywhere)
	USphereComponent* sphere_Collider;

	UPROPERTY(EditAnywhere)
	float m_speed;
    
};
