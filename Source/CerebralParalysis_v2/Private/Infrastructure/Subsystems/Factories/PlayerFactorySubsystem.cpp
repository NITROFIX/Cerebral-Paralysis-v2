// Cerebral Paralysis... Think twice ;)


#include "Infrastructure/Subsystems/Factories/PlayerFactorySubsystem.h"

#include "Infrastructure/Subsystems/Factories/PlayerProviderSubsystem.h"

APawn* UPlayerFactorySubsystem::SpawnPlayer(const TSubclassOf<APawn> DefaultPawnClass, const AActor* StartSpot) const
{
	if (!GetWorld())
		return nullptr;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Instigator = nullptr;
	SpawnParams.ObjectFlags |= RF_Transient;

	const FVector SpawnLocation = StartSpot ? StartSpot->GetActorLocation() : FVector::ZeroVector;
	const FRotator SpawnRotation = StartSpot ? StartSpot->GetActorRotation() : FRotator::ZeroRotator;

	APawn* PlayerPawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, SpawnLocation, SpawnRotation, SpawnParams);
	GetWorld()->GetGameInstance()->GetSubsystem<UPlayerProviderSubsystem>()->SetPlayer(PlayerPawn);

	return PlayerPawn;
}
