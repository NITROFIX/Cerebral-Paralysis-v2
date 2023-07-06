// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Weapons/BasicWeaponComponent.h"

#include "GameFramework/Character.h"

UBasicWeaponComponent::UBasicWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UBasicWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapons();
}


void UBasicWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (!CurrentWeapon)
		return;
	
	CurrentWeapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	CurrentWeapon->Destroy();
	CurrentWeapon = nullptr;
}

void UBasicWeaponComponent::SpawnWeapons()
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
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
	Weapon->AttachToComponent(SceneComponent, AttachmentRules, Name);
}


void UBasicWeaponComponent::StartFire() const
{
	if (!CurrentWeapon)
		return;

	CurrentWeapon->StartFire();
}

void UBasicWeaponComponent::StopFire() const
{
	if (!CurrentWeapon)
		return;

	CurrentWeapon->StopFire();
}

void UBasicWeaponComponent::ForceFire() const
{
	if (!CurrentWeapon)
		return;

	CurrentWeapon->ForceFire();
}

void UBasicWeaponComponent::SetDirection(FRotator Direction) const
{
	if (!CurrentWeapon)
		return;;

	CurrentWeapon->SetDirection(Direction);
}
