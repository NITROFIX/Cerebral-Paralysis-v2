// Cerebral Paralysis... Think twice ;)


#include "Actors/Weapons/Emitters/RaycastEmitter.h"

#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/Units/HealthComponent.h"
#include "Components/Weapons/WeaponFXComponent.h"


ARaycastEmitter::ARaycastEmitter()
{
	WeaponFXComponent2 = CreateDefaultSubobject<UWeaponFXComponent>("WeaponFXComponent");
}

void ARaycastEmitter::Emit(const FVector& Position, const FRotator Direction)
{
	Super::Emit(Position, Direction);

	if (!GetWorld())
		return;

	FVector TraceStart;
	FVector TraceEnd;

	CalculateTrace(Position, Direction, TraceStart, TraceEnd);
	FVector TraceFXEnd = TraceEnd;

	FHitResult HitResult;
	Raycast(TraceStart, TraceEnd, HitResult);

	if (HitResult.bBlockingHit)
	{
		TraceFXEnd = HitResult.ImpactPoint;
		Damage(HitResult);
	}

	WeaponFXComponent2->PlayImpactFX(HitResult);

	SpawnTraceFX(TraceStart, TraceFXEnd);
}

void ARaycastEmitter::CalculateTrace(const FVector& StartPosition, FRotator Direction, FVector& TraceStart,
                                     FVector& TraceEnd) const
{
	TraceStart = StartPosition;

	const double HalfRad = FMath::DegreesToRadians(BulletSpread);
	const FVector ShootDirection = FMath::VRandCone(Direction.Vector(), HalfRad);

	TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
}

void ARaycastEmitter::Raycast(const FVector TraceStart, const FVector TraceEnd, FHitResult& HitResult) const
{
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);
}

void ARaycastEmitter::Damage(const FHitResult HitResult) const
{
	UHealthComponent* Health = Cast<UHealthComponent>(
		HitResult.GetActor()->GetComponentByClass(UHealthComponent::StaticClass()));

	if (!Health)
		return;

	//Health->TakeDamage(Team, DamageAmount);
}

void ARaycastEmitter::ReloadFire()
{
	//CanFire = true;
}

void ARaycastEmitter::SpawnTraceFX(const FVector& TraceStart, const FVector& TraceEnd) const
{
	UNiagaraComponent* TraceFXComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
		GetWorld(), TraceFX, TraceStart);

	if (!TraceFXComponent)
		return;

	TraceFXComponent->SetNiagaraVariableVec3(TraceTargetName, TraceEnd);
}
