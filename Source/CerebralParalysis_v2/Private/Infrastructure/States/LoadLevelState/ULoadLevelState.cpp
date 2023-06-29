#include "Infrastructure/States/LoadLevelState/ULoadLevelState.h"
#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"
#include "StaticData/LevelNames.h"

void ULoadLevelState::Enter()
{
	OnLoadedDelegate.BindUObject(this, &ULoadLevelState::OnLoaded);

	UGameInstance* GameInstance = CurrentWorld->GetGameInstance();
	ULoadLevelSubsystem* LoadLevelSubsystem = GameInstance->GetSubsystem<ULoadLevelSubsystem>();
	LoadLevelSubsystem->LoadLevel(CurrentWorld, FLevelNames::Level1, OnLoadedDelegate);
}

void ULoadLevelState::OnLoaded(UWorld* World)
{
	UE_LOG(LogTemp, Warning, TEXT("I WON"));
}
