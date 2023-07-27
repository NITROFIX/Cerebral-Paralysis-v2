// Cerebral Paralysis... Think twice ;)

#pragma once

#include "Components/Weapons/PlayerWeaponComponent.h"
#include "CoreMinimal.h"
#include "Components/Weapons/BasicWeaponComponent.h"

UPlayerWeaponComponent::UPlayerWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPlayerWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	PistolWeapon = SpawnWeapon<APlayerPistol>(WeaponClass);
	SetCurrentWeapon(PistolWeapon);
}

void UPlayerWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	DestroyWeapon(PistolWeapon);
}

void UPlayerWeaponComponent::StartFire()
{
	if (!PistolWeapon)
		return;

	IsFiring = true;
}

void UPlayerWeaponComponent::StopFire()
{
	if (!PistolWeapon)
		return;

	IsFiring = false;
}

void UPlayerWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsFiring)
		PistolWeapon->Fire();
}