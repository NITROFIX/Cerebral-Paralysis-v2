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
	void SetDirection(const FRotator Direction) { FireDirection = Direction; }

	virtual void TryFire();
	virtual void MakeShot();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* WeaponMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName MuzzleSocketName = "MuzzleFlashSocket";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ETeam Team;
	
	UPROPERTY()
	FRotator FireDirection;
	
	bool IsFiring;
	bool CanFire = true;

	FTransform GetMuzzleTransform() const;
};
