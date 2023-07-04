// Cerebral Paralysis... Think twice ;)


#include "Infrastructure/Subsystems/Factories/EnemyFactorySubsystem.h"

void UEnemyFactorySubsystem::SpawnZombieSoldier(const FVector Position) const
{
	if (!GetWorld() || !DataLoaded)
		return;

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor(Data.ZombieSoldier, &Position, &FRotator::ZeroRotator, SpawnParameters);
}
