#pragma once

#include "Infrastructure/States/IStates.h"
#include "Infrastructure/States/LoadLevelState/ULoadLevelState.h"
#include "UBootstrapState.generated.h"

UCLASS()
class UBootstrapState : public UObject, public IState
{
	GENERATED_BODY()

private:
	FOnLoaded OnLoadedDelegate;
	
	UPROPERTY()
	UWorld* CurrentWorld;

	UPROPERTY()
	UGameInstance* CurrentGameInstance;

public:
	virtual void SetWorld(UWorld* NewWorld) override
	{
		CurrentWorld = NewWorld;
	}

	virtual void Enter() override;
	virtual void Exit() override;

private:
	void ConstructSubsystems(const UGameInstance* GameInstance) const;
	void OnLoaded(UWorld* World) const;
};
