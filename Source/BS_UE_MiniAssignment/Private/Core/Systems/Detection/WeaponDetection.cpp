// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Systems/Detection/WeaponDetection.h"
#include "Components/BoxComponent.h"
#include "Core/Systems/Items/Weapon.h"

// Sets default values
AWeaponDetection::AWeaponDetection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
}

void AWeaponDetection::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (auto* ItemDetected = Cast<AWeapon>(OtherActor))
	{
		if (ItemDetected->WeaponType == EWeaponType::Sword)
		{
			UE_LOG(LogTemp, Display, TEXT("Detected Sword"));
		}
		if (ItemDetected->WeaponType == EWeaponType::Axe)
		{
			UE_LOG(LogTemp, Display, TEXT("Axe"));
		}		if (ItemDetected->WeaponType == EWeaponType::Hammer)
		{
			UE_LOG(LogTemp, Display, TEXT("Detected Hammer"));
		}
	}
}

// Called when the game starts or when spawned
void AWeaponDetection::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponDetection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

