// Fill out your copyright notice in the Description page of Project Settings.


#include "Item_PickUpComponent.h"
#include "UnrealChallenge2Character.h"
#include "UnrealChallenge2_Item.h"
#include "TP_WeaponComponent.h"

UItem_PickUpComponent::UItem_PickUpComponent() {
	// Setup the Sphere Collision
	this->SphereRadius = 64.f;
}

void UItem_PickUpComponent::BeginPlay() {
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UItem_PickUpComponent::OnApproach);
}

void UItem_PickUpComponent::OnApproach(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
) {
	AUnrealChallenge2Character* Character = Cast<AUnrealChallenge2Character>(OtherActor);
	if (Character == nullptr) return;
	else UE_LOG(LogTemp, Warning, TEXT("Character detected."));

	TArray<USceneComponent*> meshChildren = Character->GetMesh1P()->GetAttachChildren();
	UTP_WeaponComponent* weaponComponent = nullptr;
	for (int i = 0; i < meshChildren.Num(); i++) {
		weaponComponent = Cast<UTP_WeaponComponent>(meshChildren[i]);
		if (weaponComponent) break;
	}

	if (weaponComponent == nullptr) return;
	else UE_LOG(LogTemp, Warning, TEXT("Gun detected."));

	AUnrealChallenge2_Item* item = Cast<AUnrealChallenge2_Item>(this->GetOwner());
	if (item == nullptr) return;
	else UE_LOG(LogTemp, Warning, TEXT("Owner is item."));

	item->ChangeWeaponMode(weaponComponent);
	UE_LOG(LogTemp, Warning, TEXT("Weapon change."));

	OnComponentBeginOverlap.RemoveAll(this);
	DestroyComponent();
}