// Cerebral Paralysis... Think twice ;)


#include "Actors/VFX/VFXPlayer.h"

#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"

AVFXPlayer::AVFXPlayer()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AVFXPlayer::BeginPlay()
{
	Super::BeginPlay();
	NiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(
		VFX,
		RootComponent,
		NAME_None, 
		FVector::ZeroVector, 
		FRotator::ZeroRotator, 
		EAttachLocation::KeepRelativeOffset, 
		true
	);
}

void AVFXPlayer::Stop() const
{
	NiagaraComponent->Deactivate();
}


