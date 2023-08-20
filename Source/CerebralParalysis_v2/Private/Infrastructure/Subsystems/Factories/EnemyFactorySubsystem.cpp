// Cerebral Paralysis... Think twice ;)


#include "Infrastructure/Subsystems/Factories/EnemyFactorySubsystem.h"

void UEnemyFactorySubsystem::SpawnZombieSoldier(const FVector Position) const
{
	if (!DataLoaded || !GetWorld())
		return;

	const TSubclassOf<AActor> Zombie = Data.ZombieSoldier;
	SpawnActor(Zombie, Position);
}

void UEnemyFactorySubsystem::SpawnAncient(const FVector Position) const
{
	if (!DataLoaded || !GetWorld())
		return;

	const TSubclassOf<AActor> Ancient = Data.Ancient;
	SpawnActor(Ancient, Position);
}


void UEnemyFactorySubsystem::SpawnActor(TSubclassOf<AActor> ActorToSpawn, const FVector Position) const
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor(ActorToSpawn, &Position, &FRotator::ZeroRotator, SpawnParameters);
}
