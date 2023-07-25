// Cerebral Paralysis... Think twice ;)


#include "Components/Weapons/AIWeaponComponent.h"

void UAIWeaponComponent::Fire()
{
	CurrentWeapon->MakeShot();
}
