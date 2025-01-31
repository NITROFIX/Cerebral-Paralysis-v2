// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Utilities/CameraMover.h"
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
	UPROPERTY(EditDefaultsOnly)
	float SpeedAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UACameraMover* CameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UPlayerWeaponComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxTeleportDistance = 1000;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TeleportChangeSpeed = 0.1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TeleportDistanceMultiplier = 100;

	float TeleportTime;
	FTimerHandle TeleportTimerHandle;
	FVector MoveVector;
	FRotator LatestRotation;
	bool bIsDashKeyPressed;

	AHeroCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	float GetMovementDirection() const;
	void SetLookRotation(FVector_NetQuantize NewAimLocation);
	FVector_NetQuantize GetAimLocation() const { return AimLocation; }

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveHorizontal(float Amount);
	void MoveVertical(float Amount);
	void StartFire();
	void StopFire();

	void TeleportInDirection(float TeleportDistance);
	void OnTeleportPressed();
	void OnTeleportReleased();
	void UpdateTeleportTime();
	void UpdateTeleportVisualization();

private:
	UPROPERTY()
	FVector_NetQuantize AimLocation;

	FVector AdjustDirectionDependingOnObjectAngle(const FVector& Direction,
	                                              const USceneComponent* TargetTransform) const;
};
