// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StaticData/ETeam.h"
#include "BaseWeapon.generated.h"

UCLASS()
class CEREBRALPARALYSIS_V2_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	ABaseWeapon();

	virtual void StartFire();
	virtual void StopFire();
	void ForceFire();
	void SetDirection(const FRotator Direction) { FireDirection = Direction; }

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* WeaponMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName MuzzleSocketName = "MuzzleFlashSocket";

	UPROPERTY(EditDefaultsOnly)
	float FireReloadTime;

	UPROPERTY()
	FRotator FireDirection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ETeam Team;

	bool IsFiring;
	bool CanFire = true;

	virtual void MakeShot();

	FTransform GetMuzzleTransform() const;

private:
	virtual void TryFire();
	virtual void Tick(float DeltaSeconds) override;
};
