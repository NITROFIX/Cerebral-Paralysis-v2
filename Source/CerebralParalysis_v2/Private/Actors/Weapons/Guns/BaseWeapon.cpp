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

void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TryFire();
}

void ABaseWeapon::StartFire()
{
	IsFiring = true;
}

void ABaseWeapon::StopFire()
{
	IsFiring = false;
}

void ABaseWeapon::MakeShot(){}

FTransform ABaseWeapon::GetMuzzleTransform() const
{
	//return WeaponMeshComponent->GetSocketTransform(MuzzleSocketName);
	return WeaponMeshComponent->GetComponentTransform();
}

void ABaseWeapon::TryFire(){}
