#include "Infrastructure/States/LoadLevelState/ULoadLevelState.h"
#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"
#include "Infrastructure/Subsystems/Factories/PlayerProviderSubsystem.h"
#include "Infrastructure/Subsystems/Generic/CursorHandlerSubsystem.h"
#include "Infrastructure/Subsystems/Providers/FirstSceneProviderSubsystem.h"
#include "StaticData/LevelNames.h"

void ULoadLevelState::Enter()
{
	OnLoadedDelegate.BindUObject(this, &ULoadLevelState::OnLoaded);

	const UGameInstance* GameInstance = CurrentWorld->GetGameInstance();
	ULoadLevelSubsystem* LoadLevelSubsystem = GameInstance->GetSubsystem<ULoadLevelSubsystem>();
	const FName LevelName = GameInstance->GetSubsystem<UFirstSceneProviderSubsystem>()->GetFirstSceneName();
	LoadLevelSubsystem->LoadLevel(CurrentWorld, LevelName, OnLoadedDelegate);
}

void ULoadLevelState::OnLoaded(UWorld* World) const
{
	APawn* Player = World->GetGameInstance()->GetSubsystem<UPlayerProviderSubsystem>()->GetPlayer();
	World->GetGameInstance()->GetSubsystem<UCursorHandlerSubsystem>()->ShowCursor(Cast<APlayerController>(Player->GetController()));
}
