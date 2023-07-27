// Cerebral Paralysis... Think twice ;)


#include "Actors/Weapons/Guns/Player/PlayerPistol.h"

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

	
	Emitter->Emit(GetMuzzleTransform().GetLocation(), FireDirection);
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
