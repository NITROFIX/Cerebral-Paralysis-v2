// Cerebral Paralysis... Think twice ;)


#include "Actors/Weapons/Guns/ProjectileWeapon.h"

void AProjectileWeapon::TryFire()
{
	if (CanFire)
		MakeShot();
}

void AProjectileWeapon::MakeShot()
{
	if (!GetWorld())
		return;
	
	FVector TraceStart;
	FVector TraceEnd;

	CalculateTrace(TraceStart, TraceEnd);

	GetWorldTimerManager().SetTimer(FireTimerHandle, this, &AProjectileWeapon::ReloadFire, FireReloadTime, false,
	                                FireReloadTime);
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	ABaseBullet* SpawnedProjectile = GetWorld()->SpawnActor<ABaseBullet>(Projectile, TraceStart, FRotator::ZeroRotator, Params);

	if (!SpawnedProjectile)
		return;

	SpawnedProjectile->SetTeam(Team);
	SpawnedProjectile->SetDirection(TraceEnd - TraceStart);
	CanFire = false;
}

void AProjectileWeapon::CalculateTrace(FVector& TraceStart, FVector& TraceEnd) const
{
	const FTransform SocketTransform = GetMuzzleTransform();
	TraceStart = SocketTransform.GetLocation();

	const double HalfRad = FMath::DegreesToRadians(BulletSpread);
	const FVector ShootDirection = FMath::VRandCone(FireDirection.Vector(), HalfRad);

	TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
}

void AProjectileWeapon::ReloadFire()
{
	CanFire = true;
}

