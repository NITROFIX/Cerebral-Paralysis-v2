// Cerebral Paralysis... Think twice ;)


#include "Actors/Weapons/Emitters/ProjectileEmitter.h"

#include "Actors/Weapons/Bullets/BaseBullet.h"
#include "Infrastructure/Subsystems/Factories/WeaponObjectsFactorySubsystem.h"

class ABaseBullet;

void AProjectileEmitter::BeginPlay()
{
	Super::BeginPlay();
	Construct();
}

void AProjectileEmitter::Construct()
{
	WeaponObjectsFactorySubsystem = GetWorld()
	                                ->GetGameInstance()
	                                ->GetSubsystem<UWeaponObjectsFactorySubsystem>();
}

void AProjectileEmitter::Emit(const FVector& Position, const FRotator Direction)
{
	if (!GetWorld())
		return;

	SpawnBullet(Position, Direction);
}

void AProjectileEmitter::SpawnBullet(const FVector& Position, FRotator Direction) const
{
	float RandomYawOffset = FMath::RandRange(-Scatter, Scatter);
	Direction.Yaw += RandomYawOffset;
	
	WeaponObjectsFactorySubsystem->CreateBullet(Projectile, Position, Direction);
}
