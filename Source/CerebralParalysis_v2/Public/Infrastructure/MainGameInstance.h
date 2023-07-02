// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UGameStateMachine.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */

UCLASS()
class CEREBRALPARALYSIS_V2_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UPROPERTY()
	UGameStateMachine* MainGameStateMachine;

	UPROPERTY()
	UWorld* CurrentWorld;
	
	bool IsInitialized;
	
public:
	UFUNCTION(BlueprintCallable, Category = "States")
	void EnterLoadLevelState();

	UGameStateMachine* GetGameStateMachine() const
	{
		return MainGameStateMachine;
	}

	UFUNCTION(BlueprintCallable)
	UWorld* GetCurrentWorld() const
	{
		return CurrentWorld;
	}

private:
	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void StartGame();
	
	virtual void OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld) override;
	UMainGameInstance();
};
