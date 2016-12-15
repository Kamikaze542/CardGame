// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "CardGamePlayerController.h"



ACardGamePlayerController::ACardGamePlayerController()
{
	static ConstructorHelpers::FObjectFinder<UBlueprint> theminion(TEXT("Blueprint'/Game/C++ClassExtensions/SmallMinion.SmallMinion'")); 
	m_thatMinion = (UClass*)theminion.Object->GeneratedClass;
	m_MaxMana = 100;
	m_CurrentMana = 0;
	bReplicates = true;
}

void ACardGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	this->InputComponent->BindAction("Raycast", EInputEvent::IE_Pressed, this, &ACardGamePlayerController::PerformRaycast);
	//this->AcknowledgedPawn->InputComponent->BindAction("Raycast", IE_Pressed, this, &ACardGamePlayerController::PerformRaycast);
	//InputComponent->BindAction("Raycast", IE_Pressed, this, &ACardGamePlayerController::PerformRaycast);
}

void ACardGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
	FInputModeGameAndUI iM;
	SetInputMode(iM);
	SetIgnoreLookInput(true);
	SetIgnoreMoveInput(true);
	SetupInputComponent();

	
	GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Red, FString::Printf(TEXT("PCSpawnTransformInfo: %s, %s"), *this->GetActorTransform().GetLocation().ToString(), *this->GetActorTransform().GetRotation().Rotator().ToString()));
}

unsigned int ACardGamePlayerController::GetMaxMana()
{
	return m_MaxMana;
}

unsigned int ACardGamePlayerController::GetCurrentMana()
{
	return m_CurrentMana;
}

bool ACardGamePlayerController::GetP1()
{
	return m_p1;
}

void ACardGamePlayerController::SetCurrentMana(unsigned int mana)
{
	m_CurrentMana = mana;
}

void ACardGamePlayerController::SetP1(bool player1)
{
	m_p1 = player1;
}

void ACardGamePlayerController::PlayCard(ECardName cardPlayed, FVector location)
{
	gm = (ACardGameGameModeBase*)GetWorld()->GetAuthGameMode();
	gm->SpawnCard(m_thatMinion, location, m_p1);
}
void ACardGamePlayerController::PlayCardNetwork_Implementation(ECardName cardPlayed, FVector location)
{
	PlayCard(cardPlayed, location);
}
bool ACardGamePlayerController::PlayCardNetwork_Validate(ECardName cardPlayed, FVector location)
{
	return true;
}

void ACardGamePlayerController::PerformRaycast()
{
	
	FHitResult* HitResult = new FHitResult();
	/////
	//float LocationX;
	//float LocationY;
	//const bool bTraceComplex = false;
	//this->GetMousePosition(LocationX, LocationY);
	//FVector2D MousePosition(LocationX, LocationY);
	//FHitResult hitResult;
	/////
	//if (this->GetHitResultAtScreenPosition(MousePosition, ECC_Visibility, bTraceComplex, hitResult))
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Red, FString::Printf(TEXT("Hit something %s, %s")));
	//}
	
	
	//FVector StartTrace = this->GetActorTransform().GetLocation();
	//FVector ForwardVector = this->GetActorForwardVector();
	//FVector EndTrace = ((ForwardVector * 50000.f) + StartTrace);
	//
	//
	//GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Red, FString::Printf(TEXT("Debug thing Working!: %s, %s"), *StartTrace.ToString(), *ForwardVector.ToString(), *EndTrace.ToString()));
	//FCollisionQueryParams* TraceParams = new FCollisionQueryParams();

	////GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Red, FString::Printf(TEXT("Camera location : %s, %s") ));
	////FVector StartTrace = this->PlayerCameraManager->GetTransformComponent()->GetComponentLocation();
	////FVector ForwardVector = this->PlayerCameraManager->GetTransformComponent()->GetForwardVector();
	////FVector EndTrace = ((ForwardVector * 50000.f) + StartTrace);
	////FCollisionQueryParams* TraceParams = new FCollisionQueryParams();
 //   
	//if (GetWorld()->LineTraceSingleByChannel(*HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams))
	//{
	//	DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(255, 0, 0), true);	
	//	GEngine->AddOnScreenDebugMessage(-1, 1000.f, FColor::Red, FString::Printf(TEXT("Hit something %s, %s"), *HitResult->Actor->GetName()));
	//	ECardName card = ECardName::SMALL_MINION;
	//	FVector* v = new FVector(1000.f,0.f,400.f);
	//	PlayCardNetwork(card, *v);

	//}



}

void ACardGamePlayerController::CardClicked(int theCard)
{
	ECardName card;
	FVector* v;
	switch (theCard)
	{
	case 0:
		card = ECardName::SMALL_MINION;
		v = new FVector(m_p1?  500.f : 2300.f, 1000.f, 600.f);
		break;
		
	case 1:
		card = ECardName::MEDIUM_MINION;
		v = new FVector(m_p1 ? 500.f : 2300.f, 500.f, 400.f);
		break;

	case 2:
		card = ECardName::LARGE_MINION;
		v = new FVector(m_p1 ? 500.f : 2300.f, 0.f, 400.f);
		break;

	case 3:
		card = ECardName::FIRE_SPELL;
		v = new FVector(1400.f, 500.f, 400.f);
		break;

	case 4:
		card = ECardName::ICE_SPELL;
		v = new FVector(1400.f, 500.f, 400.f);
		break;

	case 5:
		card = ECardName::POISON_SPELL;
		v = new FVector(1400.f, 500.f, 400.f);
		break;
	default:
		card = ECardName::SMALL_MINION;
		v = new FVector(m_p1 ? 500.f : 2300.f, 0.f, 400.f);
		break;
	}
	
	
	PlayCardNetwork(card, *v);
}