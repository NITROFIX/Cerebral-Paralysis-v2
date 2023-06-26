// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Infrastructure/States/LoadLevelState/ULoadLevelState.h"
#include "Subsystems/Subsystem.h"
#include "LoadLevelSubsystem.generated.h"

/**
 * 
 */
UCLASS()
	class CEREBRALPARALYSIS_V2_API ULoadLevelSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void Construct(UWorld* NewWorld);

	void LoadLevel(const FName& SceneName, FOnLoaded Action);
	void OnPostLoadMap(UWorld* World);

	UPROPERTY()
	UWorld* CurrentWorld;
	FOnLoaded OnLoadCallback;


private:

};
