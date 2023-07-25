// Cerebral Paralysis... Think twice ;)


#include "Components/Weapons/PlayerWeaponComponent.h"

UPlayerWeaponComponent::UPlayerWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPlayerWeaponComponent::StartFire()
{
	if (!CurrentWeapon)
		return;

	IsFiring = true;
}

void UPlayerWeaponComponent::StopFire()
{
	if (!CurrentWeapon)
		return;

	IsFiring = false;
}

void UPlayerWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsFiring)
		CurrentWeapon->TryFire();
}

