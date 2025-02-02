// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("DONKEY Tank.cpp Constructor : %s"), *GetName());
}

void ATank::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("DONKEY Tank.cpp BeginPlay avant Super::BeginPlay : %s"), *GetName());
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("DONKEY Tank.cpp BeginPlay apres Super::BeginPlay : %s"), *GetName());
}

