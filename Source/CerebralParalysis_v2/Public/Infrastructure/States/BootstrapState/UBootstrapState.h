#pragma once

#include "Infrastructure/States/IStates.h"
#include "Infrastructure/States/LoadLevelState/ULoadLevelState.h"
#include "UBootstrapState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDataLoad);
UCLASS()
class UBootstrapState : public UObject, public IState
{
	GENERATED_BODY()

	FOnLoaded OnLoadedDelegate;
	
	UPROPERTY()
	UWorld* CurrentWorld;

	UPROPERTY()
	UGameInstance* CurrentGameInstance;

public:	
	FOnDataLoad OnDataLoad;
	
	virtual void SetWorld(UWorld* NewWorld) override
	{
		CurrentWorld = NewWorld;
	}

	virtual void Enter() override;
	virtual void Exit() override;

private:
	void LoadSubsystems(const UGameInstance* GameInstance) const;
	void OnLoaded(UWorld* World) const;
};
