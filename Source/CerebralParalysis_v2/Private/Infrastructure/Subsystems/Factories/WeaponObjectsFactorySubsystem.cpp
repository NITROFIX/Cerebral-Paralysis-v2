// Cerebral Paralysis... Think twice ;)


#include "Infrastructure/Subsystems/Factories/WeaponObjectsFactorySubsystem.h"

#include "Actors/Weapons/Bullets/BaseBullet.h"

ABaseBullet* UWeaponObjectsFactorySubsystem::CreateBullet(const TSubclassOf<ABaseBullet> Projectile,
                                                          const FVector& Position,
                                                          const FRotator Direction) const
{
	if (!GetWorld())
		return nullptr;

	FVector TraceEnd;

	CalculateTrace(Position, Direction, TraceEnd);
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ABaseBullet* SpawnedProjectile =
		GetWorld()
		->SpawnActor<ABaseBullet>(Projectile, Position, FRotator::ZeroRotator, Params);

	if (!SpawnedProjectile)
		return nullptr;

	FRotator ProjectileDirection = Direction;
	ProjectileDirection.Normalize();
	SpawnedProjectile->SetDirection(ProjectileDirection.Vector());

	return SpawnedProjectile;
}

void UWeaponObjectsFactorySubsystem::CalculateTrace(const FVector& TraceStart, const FRotator Direction,
                                                    FVector& TraceEnd) const
{
	TraceEnd = TraceStart + Direction.Euler() * 9999;
}
