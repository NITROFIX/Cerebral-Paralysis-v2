// Cerebral Paralysis... Think twice ;)


#include "Infrastructure/Subsystems/Factories/EnemyFactorySubsystem.h"

void UEnemyFactorySubsystem::SpawnZombieSoldier(UWorld* World, const FVector Position) const
{
	if (!World || !DataLoaded)
		return;
	
	World->SpawnActor(Data.ZombieSoldier, &Position);
}
