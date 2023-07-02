// Cerebral Paralysis... Think twice ;)


#include "Actors/Subsystems/DataLoaders/EnemyFactoryDataLoader.h"

#include "Infrastructure/MainGameInstance.h"
#include "Infrastructure/Subsystems/Factories/EnemyFactorySubsystem.h"


void AEnemyFactoryDataLoader::BeginPlay()
{
	Super::BeginPlay();
	FScriptDelegate Delegate;
	Delegate.BindUFunction(this, FName("LoadData"));
	Cast<UMainGameInstance>(GetWorld()->GetGameInstance())->GetGameStateMachine()->GetState<UBootstrapState>()->OnDataLoad.Add(Delegate);
}

void AEnemyFactoryDataLoader::LoadData()
{
	Super::LoadData();
	GetWorld()->GetGameInstance()->GetSubsystem<UEnemyFactorySubsystem>()->Construct(Data);
}