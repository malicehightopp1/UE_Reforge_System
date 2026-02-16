// Copyright Epic Games, Inc. All Rights Reserved.

#include "BS_UE_MiniAssignmentPickUpComponent.h"

UBS_UE_MiniAssignmentPickUpComponent::UBS_UE_MiniAssignmentPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UBS_UE_MiniAssignmentPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UBS_UE_MiniAssignmentPickUpComponent::OnSphereBeginOverlap);
}

void UBS_UE_MiniAssignmentPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	ABS_UE_MiniAssignmentCharacter* Character = Cast<ABS_UE_MiniAssignmentCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
