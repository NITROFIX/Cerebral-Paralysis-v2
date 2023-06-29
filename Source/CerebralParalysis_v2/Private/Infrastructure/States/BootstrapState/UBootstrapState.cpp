#include "Infrastructure/States/BootstrapState/UBootstrapState.h"

#include "Infrastructure/MainGameInstance.h"
#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"
#include "StaticData/LevelNames.h"

void UBootstrapState::Enter()
{
	CurrentGameInstance = CurrentWorld->GetGameInstance();

	ConstructSubsystems(CurrentGameInstance);

	OnLoadedDelegate.BindUObject(this, &UBootstrapState::OnLoaded);
	CurrentGameInstance->GetSubsystem<ULoadLevelSubsystem>()->LoadLevel(CurrentWorld, FLevelNames::Bootstrap, OnLoadedDelegate);
}

void UBootstrapState::Exit()
{
}

void UBootstrapState::ConstructSubsystems(const UGameInstance* GameInstance) const
{
	
}


void UBootstrapState::OnLoaded(UWorld* World) const
{
	Cast<UMainGameInstance>(CurrentGameInstance)->GetGameStateMachina()->Enter<ULoadLevelState>();
}
