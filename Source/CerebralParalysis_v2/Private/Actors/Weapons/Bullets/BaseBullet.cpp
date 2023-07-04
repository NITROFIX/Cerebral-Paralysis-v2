// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Weapons/Bullets/BaseBullet.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "StaticData/ETeam.h"

ABaseBullet::ABaseBullet()
{
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponenent");
}

void ABaseBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseBullet::SetDirection(const FVector Direction) const
{
	ProjectileMovementComponent->Velocity = Direction * ProjectileMovementComponent->InitialSpeed;

}

