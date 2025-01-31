﻿#include "Infrastructure/States/LoadLevelState/ULoadLevelState.h"
#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"
#include "Infrastructure/Subsystems/Factories/PlayerProviderSubsystem.h"
#include "Infrastructure/Subsystems/Generic/CursorHandlerSubsystem.h"
#include "Infrastructure/Subsystems/Providers/FirstSceneProviderSubsystem.h"
#include "StaticData/LevelNames.h"

void ULoadLevelState::Construct(const UGameInstance* GameInstance)
{
	LoadLevelSubsystem = GameInstance->GetSubsystem<ULoadLevelSubsystem>();
	FirstSceneProviderSubsystem = GameInstance->GetSubsystem<UFirstSceneProviderSubsystem>();
	CursorHandlerSubsystem = GameInstance->GetSubsystem<UCursorHandlerSubsystem>();
}

void ULoadLevelState::Enter()
{
	OnLoadedDelegate.BindUObject(this, &ULoadLevelState::OnLoaded);

	const UGameInstance* GameInstance = CurrentWorld->GetGameInstance();
	Construct(GameInstance);
	
	const FName LevelName = FirstSceneProviderSubsystem->GetFirstSceneName();
	LoadLevelSubsystem->LoadLevel(CurrentWorld, LevelName, OnLoadedDelegate);
}

void ULoadLevelState::OnLoaded(UWorld* World) const
{
	APawn* Player = World->GetGameInstance()->GetSubsystem<UPlayerProviderSubsystem>()->GetPlayer();
	CursorHandlerSubsystem->ShowCursor(Cast<APlayerController>(Player->GetController()));
}
