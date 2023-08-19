#include "Infrastructure/States/BootstrapState/UBootstrapState.h"

#include "EngineUtils.h"
#include "Actors/Subsystems/DataLoader.h"
#include "Actors/Subsystems/DataLoaders/EnemyFactoryDataLoader.h"
#include "Infrastructure/MainGameInstance.h"
#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"
#include "Infrastructure/Subsystems/Providers/FirstSceneProviderSubsystem.h"
#include "StaticData/LevelNames.h"

void UBootstrapState::Construct(UGameInstance* GameInstance)
{
	FirstSceneProviderSubsystem = GameInstance->GetSubsystem<UFirstSceneProviderSubsystem>();
	LoadLevelSubsystem = GameInstance->GetSubsystem<ULoadLevelSubsystem>();
}

void UBootstrapState::Enter()
{
	CurrentGameInstance = CurrentWorld->GetGameInstance();
	Construct(CurrentGameInstance);

	OnLoadedDelegate.BindUObject(this, &UBootstrapState::OnLoaded);

	FirstSceneProviderSubsystem->SetFirstSceneName(CurrentWorld->GetFName());
	LoadLevelSubsystem->LoadLevel(CurrentWorld, FLevelNames::Bootstrap, OnLoadedDelegate);
}

void UBootstrapState::Exit()
{
}

void UBootstrapState::OnLoaded(UWorld* World) const
{
	LoadSubsystems(CurrentGameInstance);
	Cast<UMainGameInstance>(CurrentGameInstance)->GetGameStateMachine()->Enter<ULoadLevelState>();
}

void UBootstrapState::LoadSubsystems(const UGameInstance* GameInstance) const
{
	for (TActorIterator<ADataLoader> It(CurrentWorld); It; ++It)
	{
		ADataLoader* DataLoader = *It;
		DataLoader->LoadData();
	}
	UE_LOG(LogTemp, Warning, TEXT("End of construction"))
}
