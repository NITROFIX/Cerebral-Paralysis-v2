// Cerebral Paralysis... Think twice ;)


#include "Components/Weapons/BasicWeaponComponent.h"

#include "GameFramework/Character.h"

class ABaseWeapon;

UBasicWeaponComponent::UBasicWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UBasicWeaponComponent::DestroyWeapon(ABaseWeapon* Weapon) const
{
	Weapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	Weapon->Destroy();
	Weapon = nullptr;
}


void UBasicWeaponComponent::AttachWeaponToSocket(ABaseWeapon* Weapon, USceneComponent* SceneComponent, const FName& Name) const
{
	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
	Weapon->AttachToComponent(SceneComponent, AttachmentRules, Name);
}

void UBasicWeaponComponent::SetAimLocation(FVector TargetLocation) const
{
	if (!CurrentBaseWeapon)
		return;;

	CurrentBaseWeapon->SetAimLocation(TargetLocation);
}
