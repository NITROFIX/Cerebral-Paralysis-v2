// Cerebral Paralysis... Think twice ;)


#include "Actors/Subsystems/DataLoaders/EnemyFactoryDataLoader.h"

#include "Infrastructure/MainGameInstance.h"
#include "Infrastructure/Subsystems/Factories/EnemyFactorySubsystem.h"


void AEnemyFactoryDataLoader::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyFactoryDataLoader::LoadData()
{
	Super::LoadData();
	GetWorld()->GetGameInstance()->GetSubsystem<UEnemyFactorySubsystem>()->Construct(Data);
}