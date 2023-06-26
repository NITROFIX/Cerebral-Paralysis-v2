#pragma once
#include "Infrastructure/States/IStates.h"
#include "UBootstrapState.generated.h"

UCLASS()
class UBootstrapState : public UObject, public IState
{
	GENERATED_BODY()

private:
	UPROPERTY()
	UWorld* CurrentWorld;
	
public:
	virtual void SetWorld(UWorld* NewWorld) override
	{
		CurrentWorld = NewWorld;
	}

	virtual void Enter() override;
	virtual void Exit() override;

private:
	void ConstructSubsystems(const UGameInstance* GameInstance) const;
};
