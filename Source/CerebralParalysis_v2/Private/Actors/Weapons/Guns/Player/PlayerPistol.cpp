// Cerebral Paralysis... Think twice ;)


#include "Actors/Weapons/Guns/Player/PlayerPistol.h"

#include "Components/Weapons/WeaponFXComponent.h"


void APlayerPistol::BeginPlay()
{
	Super::BeginPlay();
	Emitter = Cast<ASingleShotEmitter>(GetWorld()->SpawnActor(EmitterClass));
	Emitter->SetOwner(GetOwner());
}

void APlayerPistol::Fire()
{
	if (CanFire == false)
		return;

	
	Emitter->Emit(GetMuzzleTransform().GetLocation(),  (TargetLocation - GetMuzzleTransform().GetLocation()).Rotation());
	SetReloading();
}

void APlayerPistol::SetReloading()
{
	GetWorldTimerManager().SetTimer(FireTimerHandle,
	                                this,
	                                &APlayerPistol::ReloadFire,
	                                ReloadTime,
	                                false,
	                                ReloadTime);

	CanFire = false;
}

void APlayerPistol::ReloadFire()
{
	CanFire = true;
}
