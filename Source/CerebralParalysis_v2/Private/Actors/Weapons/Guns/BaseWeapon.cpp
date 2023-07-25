// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Weapons/Guns/BaseWeapon.h"

ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = true;
	WeaponMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("Skeletal Mesh");
	SetRootComponent(WeaponMeshComponent);
}

void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	check(WeaponMeshComponent);
}

void ABaseWeapon::TryFire(){}

void ABaseWeapon::MakeShot(){}

FTransform ABaseWeapon::GetMuzzleTransform() const
{
	return WeaponMeshComponent->GetComponentTransform();
}


