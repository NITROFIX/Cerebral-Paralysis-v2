// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class CEREBRALPARALYSIS_V2_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	ABaseWeapon();
	void SetDirection(const FRotator Direction) { FireDirection = Direction; }

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* WeaponMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName MuzzleSocketName = "MuzzleFlashSocket";
	
	UPROPERTY()
	FRotator FireDirection;

	FTransform GetMuzzleTransform() const;
};
