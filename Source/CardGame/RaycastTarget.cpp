// Fill out your copyright notice in the Description page of Project Settings.

#include "CardGame.h"
#include "RaycastTarget.h"


// Sets default values
ARaycastTarget::ARaycastTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARaycastTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARaycastTarget::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

