// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) 
{
	//UE_LOG(LogTemp, Warning, TEXT("AimAt"));
	if (!Barrel)
	{ 
		UE_LOG(LogTemp, Warning, TEXT("NO BARREL"));
		return; 
	}
	
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	float Time = GetWorld()->GetTimeSeconds();

	if (bHaveAimSolution) 
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal(); 
		UE_LOG(LogTemp, Warning, TEXT("%f : Aim solution found"), Time);
		MoveBarrelTowards(AimDirection);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%f : No aim solution found"), Time);
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	//UE_LOG(LogTemp, Warning, TEXT("SetBarrelReference"));
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Current FRotator of the barrel
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	// Current FRotator of the aim
	FRotator AimAsRotator = AimDirection.Rotation();
	// Difference between the two
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;

	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator : %s"), *AimAsRotator.ToString());

	Barrel->Elevate(5);
}