// Cerebral Paralysis... Think twice ;)


#include "Components/Weapons/BasicWeaponComponent.h"

#include "GameFramework/Character.h"

UBasicWeaponComponent::UBasicWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UBasicWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
}

void UBasicWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (!CurrentWeapon)
		return;
	
	CurrentWeapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	CurrentWeapon->Destroy();
	CurrentWeapon = nullptr;
}

void UBasicWeaponComponent::SpawnWeapon()
{
	if (!GetWorld())
		return;

	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character)
		return;

	ABaseWeapon* Weapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass);

	if (!Weapon)
		return;

	Weapon->SetOwner(Character);
 
	AttachWeaponToSocket(Weapon, Character->GetMesh(), SocketName);
	CurrentWeapon = Weapon;
}

void UBasicWeaponComponent::AttachWeaponToSocket(ABaseWeapon* Weapon, USceneComponent* SceneComponent, const FName& Name) const
{
	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
	Weapon->AttachToComponent(SceneComponent, AttachmentRules, Name);
}


void UBasicWeaponComponent::SetDirection(const FRotator Direction) const
{
	if (!CurrentWeapon)
		return;;

	CurrentWeapon->SetDirection(Direction);
}