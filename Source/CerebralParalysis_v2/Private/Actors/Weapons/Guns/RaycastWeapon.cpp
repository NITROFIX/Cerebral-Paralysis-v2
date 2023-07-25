// Cerebral Paralysis... Think twice ;)


#include "Actors/Weapons/Guns/RaycastWeapon.h"
#include "NiagaraComponent.h"
#include "Components/Units/HealthComponent.h"
#include "NiagaraFunctionLibrary.h"

class UHealthComponent;

ARaycastWeapon::ARaycastWeapon()
{
	WeaponFXComponent = CreateDefaultSubobject<UWeaponFXComponent>("WeaponFXComponent");
}

void ARaycastWeapon::TryFire()
{
	if (CanFire)
		MakeShot();
}

void ARaycastWeapon::MakeShot()
{
	if (!GetWorld())
		return;

	FVector TraceStart;
	FVector TraceEnd;
	
	CalculateTrace(TraceStart, TraceEnd);
	FVector TraceFXEnd = TraceEnd;

	FHitResult HitResult;
	Raycast(TraceStart, TraceEnd, HitResult);
	
	if (HitResult.bBlockingHit)
	{
		TraceFXEnd = HitResult.ImpactPoint;
		Damage(HitResult);
	}
	
	WeaponFXComponent->PlayImpactFX(HitResult);
	CanFire = false;
	
	SpawnTraceFX(TraceStart, TraceFXEnd);
	GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ARaycastWeapon::ReloadFire, FireReloadTime, false,
	                                FireReloadTime);
}

void ARaycastWeapon::CalculateTrace(FVector& TraceStart, FVector& TraceEnd) const
{
	const FTransform SocketTransform = GetMuzzleTransform();
	TraceStart = SocketTransform.GetLocation();

	const double HalfRad = FMath::DegreesToRadians(BulletSpread);
	const FVector ShootDirection = FMath::VRandCone(FireDirection.Vector(), HalfRad);

	TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
}

void ARaycastWeapon::Raycast(const FVector TraceStart, const FVector TraceEnd, FHitResult& HitResult) const
{
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);
}

void ARaycastWeapon::Damage(const FHitResult HitResult) const
{
	UHealthComponent* Health = Cast<UHealthComponent>(HitResult.GetActor()->GetComponentByClass(UHealthComponent::StaticClass()));

	if (!Health)
		return;
	
	Health->TakeDamage(Team, DamageAmount);
}

void ARaycastWeapon::ReloadFire()
{
	CanFire = true;
}

void ARaycastWeapon::SpawnTraceFX(const FVector& TraceStart, const FVector& TraceEnd) const
{
	UNiagaraComponent* TraceFXComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
		GetWorld(), TraceFX, TraceStart);
	
	if (!TraceFXComponent)
		return;
	
	TraceFXComponent->SetNiagaraVariableVec3(TraceTargetName, TraceEnd);
}
