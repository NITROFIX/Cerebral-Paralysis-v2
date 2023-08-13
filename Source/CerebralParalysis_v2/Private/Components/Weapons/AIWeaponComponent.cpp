// Cerebral Paralysis... Think twice ;)


#include "Components/Weapons/AIWeaponComponent.h"

void UAIWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentWeapon = SpawnWeapon<AAIBaseWeapon>(WeaponClass);
	SetCurrentWeapon(CurrentWeapon);
}

void UAIWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	DestroyWeapon(CurrentWeapon);
}

void UAIWeaponComponent::Fire(const EAIAttackType AttackType)
{
	CurrentWeapon->Fire(AttackType);
}
