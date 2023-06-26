#pragma once
#include "UObject/ObjectRename.h"

class IExitableState
{
public:
	virtual ~IExitableState() = default;
	virtual void Exit() {};
	virtual void SetWorld(UWorld* NewWorld) {};
};

class IState : public IExitableState
{
public:
	virtual void Enter() {};
};

class IPayloadedState : public IExitableState
{
public:
	virtual void Enter(UObject* Object) {};
};
