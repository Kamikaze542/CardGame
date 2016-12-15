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
	sphere_Collider->OnComponentEndOverlap.AddDynamic(this, &AMinion::OnOverlapEnd);
	m_Luck = 100;
	m_Belief = 10;
	m_BeliefAcuity = 2.5f;
	m_speed = 1000.f;
	m_inRange = true;
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
	if (m_inRange)
	{
		
		//GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Green, FString::Printf(TEXT("arrrrg2, %f"), m_BeliefAcuity));
		m_elapsedTime += DeltaTime;
	}
	if (m_elapsedTime >= m_BeliefAcuity)
	{
		
		if (m_otherMinion != nullptr)
		{
			m_otherMinion->SetLuck(m_otherMinion->GetLuck() - m_Belief);
		}
		else if(m_otherBase != nullptr)
		{
			m_otherBase->SetCurrentHealth(m_otherBase->GetCurrentHealth() - m_Belief);
		}
		m_elapsedTime = 0.0f;
	}
	if (m_Luck <= 0)
	{
		Destroy();
	}
}

unsigned int AMinion::GetLuck()
{
	return m_Luck;
}

unsigned int AMinion::GetBelief()
{
	return m_Belief;
}

float AMinion::GetBeliefAcuity()
{
	return m_BeliefAcuity;
}

bool AMinion::GetTeam1()
{
	return m_team;
}

void AMinion::SetLuck(unsigned int Luck)
{
	m_Luck = Luck;
}

void AMinion::SetBelief(unsigned int Belief)
{
	m_Belief = Belief;
}

void AMinion::SetBeliefAcuity(float BA)
{
	m_BeliefAcuity = BA;
}

void AMinion::SetTeam1(bool team1)
{
	m_team = team1;
	GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Green, FString::Printf(TEXT("BoolBRo: %d"), m_team));
}

void AMinion::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Minion"))
	{
		m_teamCheck = (AMinion*)OtherActor;
		if (m_teamCheck->GetTeam1() == this->m_team)
		{
			m_teamCheck = nullptr;
			return;
		}
		m_teamCheck = nullptr;
		if (m_otherMinions.Num() == 0)
		{
			m_speedHolder = m_speed;
		}
		m_speed = 0.0f;
		m_otherMinions.Add((AMinion*)OtherActor);
		m_otherMinion = m_otherMinions[0];
		m_inRange = true;
	}
	
	if (OtherActor->ActorHasTag("Base"))
	{
		m_otherBase = (ABase*)OtherActor;
		if (m_otherBase->GetTeam1() != this->m_team)
		{
			m_speed = 0.0f;
			m_inRange = true;
		}
	}
}

void AMinion::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->ActorHasTag("Minion"))
	{
		m_teamCheck = (AMinion*)OtherActor;
		if (m_teamCheck->GetTeam1() == this->m_team)
		{
			m_teamCheck = nullptr;
			return;
		}
		m_teamCheck = nullptr;
		m_elapsedTime = 0.0f;
		if (m_otherMinions.Num() > 1)
		{
			m_otherMinions.RemoveAt(0);
			m_otherMinion = m_otherMinions[0];
		}
		else if (m_otherMinions.Num() == 1)
		{
			m_inRange = false;
			m_otherMinions.RemoveAt(0);
			m_otherMinion = nullptr;
			m_speed = m_speedHolder;
		}
		else
		{
			m_inRange = false;
			m_speed = m_speedHolder;
		}
	}
}



