// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "Spell.h"


// Sets default values
ASpell::ASpell()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	m_SphereCollider->SetupAttachment(RootComponent);
	m_SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	m_SphereCollider->OnComponentEndOverlap.AddDynamic(this, &ASpell::OnOverlapEnd);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	GetCapsuleComponent()->SetEnableGravity(false);
	m_AOERadius = 100.f;
	m_DamageValue = 50.f;
	m_causesStatusEffect = true;
	m_SlowFactor = 2.f;
}

// Called when the game starts or when spawned
void ASpell::BeginPlay()
{
	Super::BeginPlay();

	m_SphereCollider->SetSphereRadius(m_AOERadius, true);

	
}

// Called every frame
void ASpell::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	if (m_AffectedMinions.Num() > 0)
	{
		for (int i = 0; i < m_AffectedMinions.Num(); i++)
		{
			if (m_isDOT)
			{
				m_AffectedMinions[i]->SetLuck(m_AffectedMinions[i]->GetLuck() - m_DamageValue * DeltaTime);
			}
		}
	}
}

void ASpell::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Minion"))
	{
		m_CollidingMinion = (AMinion*)OtherActor;
		if (m_CollidingMinion->GetTeam1() == this->m_IsTeam1)
		{
			m_CollidingMinion = nullptr;
			return;
		}
		if (m_isDOT)
		{
			m_AffectedMinions.Add((AMinion*)OtherActor);
		}
		else
		{
			m_CollidingMinion->SetLuck(m_CollidingMinion->GetLuck() - m_DamageValue);
		}
		if (m_causesStatusEffect)
		{
			m_CollidingMinion->SetBeliefAcuity(m_CollidingMinion->GetBeliefAcuity() / m_SlowFactor);
		}

		m_CollidingMinion = nullptr;
	}
}

void ASpell::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->ActorHasTag("Minion"))
	{
		m_CollidingMinion = (AMinion*)OtherActor;
		if (m_CollidingMinion->GetTeam1() == this->m_IsTeam1)
		{
			m_CollidingMinion = nullptr;
			return;
		}
		if (m_isDOT)
		{
			m_AffectedMinions.Remove(m_CollidingMinion);
		}
		if (m_causesStatusEffect)
		{
			m_CollidingMinion->SetBeliefAcuity(m_CollidingMinion->GetBeliefAcuity() * m_SlowFactor);
		}

		m_CollidingMinion = nullptr;
	}
}

bool ASpell::GetCausesStatusEffect()
{
	return m_causesStatusEffect;
}

bool ASpell::GetIsDOT()
{
	return m_isDOT;
}

unsigned int ASpell::GetDamageValue()
{
	return m_DamageValue;
}

float ASpell::GetAOERadius()
{
	return m_AOERadius;
}

bool ASpell::GetIsTeam1()
{
	return m_IsTeam1;
}

float ASpell::GetSlowFactor()
{
	return m_SlowFactor;
}

void ASpell::SetCausesStatusEffect(bool SE)
{
	m_causesStatusEffect = SE;
}

void ASpell::SetIsDOT(bool DOT)
{
	m_isDOT = DOT;
}

void ASpell::SetDamageValue(int Dmg)
{
	m_DamageValue = Dmg;
}

void ASpell::SetAOERadius(float Size)
{
	m_AOERadius = Size;
}

void ASpell::SetIsTeam1(bool Team1)
{
	m_IsTeam1 = Team1;
}

void ASpell::SetSlowFactor(float SlowFactor)
{
	m_SlowFactor = SlowFactor;
}

