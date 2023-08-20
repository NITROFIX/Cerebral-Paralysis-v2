// Cerebral Paralysis... Think twice ;)


#include "Actors/Weapons/Guns/Player/PlayerPistol.h"
#include "Infrastructure/Subsystems/MusicSequencerSubsystem.h"


void APlayerPistol::Construct()
{
	MusicSequencerSubsystem = GetGameInstance()->GetSubsystem<UMusicSequencerSubsystem>();
}

void APlayerPistol::BeginPlay()
{
	Super::BeginPlay();

	Construct();

	Emitter = Cast<ASingleShotEmitter>(GetWorld()->SpawnActor(EmitterClass));
	Emitter->SetOwner(GetOwner());
	
	MusicSequencerSubsystem->OnPlayerHit.AddDynamic(this, &APlayerPistol::OnMusicPlayerHit);
}

void APlayerPistol::ForceFire()
{
	Emitter->Emit(GetMuzzleTransform().GetLocation(), (TargetLocation - GetMuzzleTransform().GetLocation()).Rotation());
}

void APlayerPistol::StartFire()
{
	IsFiring = true;
}

void APlayerPistol::StopFire()
{
	IsFiring = false;
}

void APlayerPistol::OnMusicPlayerHit()
{
	if (IsFiring)
		ForceFire();
}
