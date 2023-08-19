#pragma once

#include "Infrastructure/States/IStates.h"
#include "Infrastructure/States/LoadLevelState/ULoadLevelState.h"
#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"
#include "Infrastructure/Subsystems/Providers/FirstSceneProviderSubsystem.h"
#include "UBootstrapState.generated.h"

UCLASS()
class UBootstrapState : public UObject, public IState
{
	GENERATED_BODY()
	
public:	
	virtual void SetWorld(UWorld* NewWorld) override
	{
		CurrentWorld = NewWorld;
	}

	void Construct(UGameInstance* GameInstance);
	virtual void Enter() override;
	virtual void Exit() override;

private:
	FOnLoaded OnLoadedDelegate;
	
	UPROPERTY()
	UWorld* CurrentWorld;

	UPROPERTY()
	UGameInstance* CurrentGameInstance;

	UPROPERTY()
	UFirstSceneProviderSubsystem* FirstSceneProviderSubsystem;

	UPROPERTY()
	ULoadLevelSubsystem* LoadLevelSubsystem;
	
	void LoadSubsystems(const UGameInstance* GameInstance) const;
	void OnLoaded(UWorld* World) const;
	
};
