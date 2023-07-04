// Cerebral Paralysis... Think twice ;)


#include "Actors/Weapons/Guns/ProjectileWeapon.h"

void AProjectileWeapon::TryFire()
{
	if (IsFiring && CanFire)
		MakeShot();
}

void AProjectileWeapon::MakeShot()
{
	if (!GetWorld())
		return;
	
	UE_LOG(LogTemp, Warning, TEXT("GAAA"));

	FVector TraceStart;
	FVector TraceEnd;
	
	CalculateTrace(TraceStart, TraceEnd);

	GetWorldTimerManager().SetTimer(FireTimerHandle, this, &AProjectileWeapon::ReloadFire, FireReloadTime, false,
									FireReloadTime);
	ABaseBullet* SpawnedProjectile = GetWorld()->SpawnActor<ABaseBullet>(Projectile, TraceStart, FRotator::ZeroRotator);
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

