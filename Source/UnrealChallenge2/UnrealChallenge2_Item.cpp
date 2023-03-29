// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealChallenge2_Item.h"
#include "TP_WeaponComponent.h"

// Sets default values
AUnrealChallenge2_Item::AUnrealChallenge2_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUnrealChallenge2_Item::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnrealChallenge2_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUnrealChallenge2_Item::ChangeWeaponMode(UTP_WeaponComponent* weaponComponent) {
	weaponComponent->SetProjectileMode(ProjectileClass);
	if (crate) crate->Destroy();
	Destroy();
}

void AUnrealChallenge2_Item::SetCrate(AActor* spawner) {
	crate = spawner;
}