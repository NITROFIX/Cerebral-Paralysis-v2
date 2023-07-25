// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/Weapons/BasicWeaponComponent.h"
#include "Components/Weapons/PlayerWeaponComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeroCharacter.generated.h"

UCLASS()
class CEREBRALPARALYSIS_V2_API AHeroCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AHeroCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	float GetMovementDirection() const;
	void SetLookRotation(FVector_NetQuantize Vector);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveHorizontal(float Amount);
	void MoveVertical(float Amount);
	void StartFire();
	void StopFire();
	FVector MoveVector;
	FRotator LatestRotation;

	UPROPERTY(EditDefaultsOnly)
	float SpeedAmount;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	UPlayerWeaponComponent* WeaponComponent;

private:
	FVector AdjustDirectionDependingOnObjectAngle(const FVector& Direction, const USceneComponent* TargetTransform) const;
};

