// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "Engine/World.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet) { return; }
	if (!RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack) { return; }
	if (!RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack) { return; }
	if (!RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();

	float ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	float RightThrow = FVector::CrossProduct(AIForwardIntention, TankForward).Z;

	IntendMoveForward(ForwardThrow);
	IntendTurnRight(RightThrow);

	//UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *TankName, *MoveVelocityString);
}

