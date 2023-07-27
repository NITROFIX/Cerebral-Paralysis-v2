// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Guns/BaseWeapon.h"
#include "NiagaraComponent.h"
#include "Components/Weapons/WeaponFXComponent.h"
#include "RaycastWeapon.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API ARaycastWeapon : public ABaseWeapon
{
	ARaycastWeapon();
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	float DamageAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TraceMaxDistance = 1500;

	UPROPERTY(VisibleAnywhere, Category = "VFX")
	UWeaponFXComponent* WeaponFXComponent;

	UPROPERTY(EditDefaultsOnly)
	double BulletSpread;

	UPROPERTY(EditDefaultsOnly)
	UNiagaraSystem* TraceFX;

	UPROPERTY(EditDefaultsOnly)
	FString TraceTargetName = "TraceTarget";

	UPROPERTY(EditDefaultsOnly)
	float FireReloadTime;

	FTimerHandle FireTimerHandle;
	
private:
	virtual void TryFire();
	virtual void MakeShot();

	void CalculateTrace(FVector& TraceStart, FVector& TraceEnd) const;
	void Raycast(FVector TraceStart, FVector TraceEnd, FHitResult& HitResult) const;
	void Damage(FHitResult HitResult) const;
	void ReloadFire();
	void SpawnTraceFX(const FVector& TraceStart, const FVector& TraceEnd) const;
};
