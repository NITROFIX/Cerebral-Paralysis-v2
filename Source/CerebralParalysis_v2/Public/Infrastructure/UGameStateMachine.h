#pragma once
#include "States/IStates.h"
#include "States/BootstrapState/UBootstrapState.h"
#include "States/LoadLevelState/ULoadLevelState.h"
#include "UGameStateMachine.generated.h"

UCLASS()
class UGameStateMachine : public UObject
{
	GENERATED_BODY()

	TMap<UClass*, IExitableState*> States;
	IExitableState* CurrentState;

	UPROPERTY()
	TArray<UObject*> AntiGarbageStateObjects;

public:
	void CreateStates()
	{
		CreateState<UBootstrapState>();
		CreateState<ULoadLevelState>();
	}

	void SetWorld(UWorld* World)
	{
		for (TTuple<UClass*, IExitableState*> State : States)
			State.Value->SetWorld(World);
	}

	template <typename TState>
	void Enter()
	{
		IState* state = LoadState<TState>();
		state->Enter();
	}

	template <typename TState>
	void Enter(UObject* payload)
	{
		TState* state = LoadState<TState>();
		state->Enter(payload);
	}

	template <typename TState>
	TState* GetState()
	{
		UClass* stateClass = TState::StaticClass();
		return static_cast<TState*>(States[stateClass]);
	}

private:
	template <typename TState>
	TState* LoadState()
	{
		if (CurrentState)
			CurrentState->Exit();

		TState* state = GetState<TState>();
		CurrentState = state;
		return state;
	}

	template <typename TState>
	void CreateState()
	{
		TState* State = NewObject<TState>(this);
		States.Add(TState::StaticClass(), State);
		AntiGarbageStateObjects.Add(State);
	}
};
