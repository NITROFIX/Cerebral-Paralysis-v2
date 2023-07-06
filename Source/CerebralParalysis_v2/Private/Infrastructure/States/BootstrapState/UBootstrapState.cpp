#include "Infrastructure/States/BootstrapState/UBootstrapState.h"

#include "EngineUtils.h"
#include "Actors/Subsystems/DataLoader.h"
#include "Actors/Subsystems/DataLoaders/EnemyFactoryDataLoader.h"
#include "Infrastructure/MainGameInstance.h"
#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"
#include "Infrastructure/Subsystems/Providers/FirstSceneProviderSubsystem.h"
#include "StaticData/LevelNames.h"

void UBootstrapState::Enter()
{
	CurrentGameInstance = CurrentWorld->GetGameInstance();

	OnLoadedDelegate.BindUObject(this, &UBootstrapState::OnLoaded);

	CurrentGameInstance->GetSubsystem<UFirstSceneProviderSubsystem>()->SetFirstSceneName(CurrentWorld->GetFName());
	CurrentGameInstance->GetSubsystem<ULoadLevelSubsystem>()->LoadLevel(CurrentWorld, FLevelNames::Bootstrap, OnLoadedDelegate);
}

void UBootstrapState::Exit()
{
}

void UBootstrapState::LoadSubsystems(const UGameInstance* GameInstance) const
{
	for (TActorIterator<ADataLoader> It(CurrentWorld); It; ++It)
	{
		ADataLoader* Actor = *It;
		Actor->LoadData();
	}
	UE_LOG(LogTemp, Warning, TEXT("End of constuction"))
}


void UBootstrapState::OnLoaded(UWorld* World) const
{
	LoadSubsystems(CurrentGameInstance);
	Cast<UMainGameInstance>(CurrentGameInstance)->GetGameStateMachine()->Enter<ULoadLevelState>();
}
