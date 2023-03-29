// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnrealChallenge2_Item.generated.h"

class UTP_WeaponComponent;

UCLASS()
class UNREALCHALLENGE2_API AUnrealChallenge2_Item : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnrealChallenge2_Item();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Projectile") void ChangeWeaponMode(UTP_WeaponComponent* weaponComponent);
	UFUNCTION(BlueprintCallable, Category = "Crate") void SetCrate(AActor* spawner);

	UPROPERTY(EditDefaultsOnly, Category = Projectile) TSubclassOf<class AUnrealChallenge2Projectile> ProjectileClass;

protected:
	AActor* crate = nullptr;
};