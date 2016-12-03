// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "Minion.h"


// Sets default values
AMinion::AMinion()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    sphere_Collider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	sphere_Collider->SetupAttachment(RootComponent);
	sphere_Collider->SetSphereRadius(100.f, true);
	sphere_Collider->OnComponentBeginOverlap.AddDynamic(this, &AMinion::OnOverlapBegin);
	m_Luck = 1;
	m_Belief = 1;
	m_speed = 1000.f;
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
	float zVel = GetVelocity().Z;
	GetCharacterMovement()->Velocity = GetActorForwardVector() * m_speed + FVector(0.0f, 0.0f, zVel);
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

void AMinion::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	 GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Some debug message!"));
	if (OtherActor->ActorHasTag("Minion"))
	{
		m_speed = 0.0f;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
	}
}



