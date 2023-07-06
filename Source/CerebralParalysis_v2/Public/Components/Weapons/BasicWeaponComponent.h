// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Guns/BaseWeapon.h"
#include "Components/ActorComponent.h"
#include "BasicWeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CEREBRALPARALYSIS_V2_API UBasicWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UBasicWeaponComponent();

	UFUNCTION(BlueprintCallable)
	void StartFire() const;

	UFUNCTION(BlueprintCallable)
	void StopFire() const;

	UFUNCTION(BlueprintCallable)
	void ForceFire() const;
	
	void NextWeapon();

	UFUNCTION(BlueprintCallable)
	void SetDirection(FRotator Direction) const;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<ABaseWeapon> WeaponClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName SocketName = "WeaponSocket";

private:
	void AttachWeaponToSocket(ABaseWeapon* Weapon, USceneComponent* Mesh, const FName& Name) const;

	UPROPERTY()
	ABaseWeapon* CurrentWeapon = nullptr;

	void SpawnWeapons();
};
