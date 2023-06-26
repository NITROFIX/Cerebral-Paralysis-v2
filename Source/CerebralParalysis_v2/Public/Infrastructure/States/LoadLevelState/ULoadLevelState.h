#pragma once

#include "Infrastructure/States/IStates.h"
#include "ULoadLevelState.generated.h"


DECLARE_DELEGATE_OneParam(FOnLoaded, UWorld*);
UCLASS()
class ULoadLevelState : public UObject, public IState
{
	GENERATED_BODY()

	ULoadLevelState();

private:
	UPROPERTY()
	UWorld* CurrentWorld;

	FOnLoaded OnLoadedDelegate;

public:
	virtual void SetWorld(UWorld* NewWorld) override
	{
		CurrentWorld = NewWorld;
	}

	virtual void Enter() override;
	void OnLoaded(UWorld* World);
};
