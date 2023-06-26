#include "Infrastructure/States/LoadLevelState/ULoadLevelState.h"
#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"
#include "StaticData/LevelNames.h"


ULoadLevelState::ULoadLevelState()
{
	OnLoadedDelegate.BindUObject(this, &ULoadLevelState::OnLoaded);
}

void ULoadLevelState::Enter()
{
	IState::Enter();
	
	CurrentWorld->GetGameInstance()->GetSubsystem<ULoadLevelSubsystem>()->LoadLevel(LevelNames::Level1, OnLoadedDelegate);
}

void ULoadLevelState::OnLoaded(UWorld* World)
{
	UE_LOG(LogTemp, Warning, TEXT("I WON"));
}
