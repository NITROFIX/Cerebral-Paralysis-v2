#pragma once

#include "Delegates/Delegates.h"
#include "Infrastructure/States/IStates.h"
#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"
#include "Infrastructure/Subsystems/Generic/CursorHandlerSubsystem.h"
#include "Infrastructure/Subsystems/Providers/FirstSceneProviderSubsystem.h"
#include "ULoadLevelState.generated.h"


UCLASS()
class ULoadLevelState : public UObject, public IState
{
	GENERATED_BODY()

private:
	UPROPERTY()
	UWorld* CurrentWorld;

	FOnLoaded OnLoadedDelegate;

	UPROPERTY()
	ULoadLevelSubsystem* LoadLevelSubsystem;

	UPROPERTY()
	UFirstSceneProviderSubsystem* FirstSceneProviderSubsystem;

	UPROPERTY()
	UCursorHandlerSubsystem* CursorHandlerSubsystem;

public:
	virtual void SetWorld(UWorld* NewWorld) override
	{
		CurrentWorld = NewWorld;
	}

	void Construct(const UGameInstance* GameInstance);
	virtual void Enter() override;
	void OnLoaded(UWorld* World) const;
};
