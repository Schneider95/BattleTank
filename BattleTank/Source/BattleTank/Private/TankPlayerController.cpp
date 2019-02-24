#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is not possessing a tank !"));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController possess %s"), *(ControlledTank->GetName()));
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("PlayerController tick !"));
	//AimTowardsCrosshair
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
}
