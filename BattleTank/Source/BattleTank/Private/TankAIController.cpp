#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	APawn* ControlledTank = GetPawn();

	if (!ensure(PlayerTank)) { return; }
	if (!ensure(ControlledTank)) { return; }

	MoveToActor(PlayerTank, AcceptanceRadius);

	UTankAimingComponent* TankAimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(TankAimingComponent)) { return; }

	TankAimingComponent->AimAt(PlayerTank->GetActorLocation());
	TankAimingComponent->Fire();
}
