#include "TankAIController.h"
#include "BattleTank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ControlledTank not found for AI Tank !"));
	}

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank %s didn't found Player Tank !"), *(ControlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("ControlledTank found for AI Tank : %s"), *(ControlledTank->GetName()));
	UE_LOG(LogTemp, Warning, TEXT("AI Tank %s found Player Tank : %s"), *(ControlledTank->GetName()), *(PlayerTank->GetName()));
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn)
	{
		return nullptr;
	}

	return Cast<ATank>(PlayerPawn);
}
