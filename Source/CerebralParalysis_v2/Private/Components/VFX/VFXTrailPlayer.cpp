// Cerebral Paralysis... Think twice ;)


#include "Components/VFX/VFXTrailPlayer.h"

#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"

UVFXTrailPlayer::UVFXTrailPlayer()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UVFXTrailPlayer::BeginPlay()
{
	Super::BeginPlay();

	if (AutoPlay)
		SpawnSystem();
}

void UVFXTrailPlayer::SpawnSystem()
{
	const FActorSpawnParameters Params;
	CurrentTrailActor = GetWorld()->SpawnActor<AVFXPlayer>(TrailActor, GetComponentLocation(), FRotator::ZeroRotator, Params);

	CurrentTrailActor->AttachToActor(GetOwner(), FAttachmentTransformRules::KeepWorldTransform);
}

void UVFXTrailPlayer::DetachSystem() const
{
	CurrentTrailActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	CurrentTrailActor->Stop();
}

void UVFXTrailPlayer::DestroyTrailActor()
{
	if (!CurrentTrailActor)
		return;

	GetWorld()->DestroyActor(Cast<AActor> (CurrentTrailActor));
	CurrentTrailActor = nullptr;
}

