// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Delegates/Delegates.h"
#include "LoadLevelSubsystem.generated.h"

/**
 * 
 */
UCLASS()
	class CEREBRALPARALYSIS_V2_API ULoadLevelSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void LoadLevel(const UWorld* CurrentWorld, const FName& SceneName, FOnLoaded Action);
	void OnPostLoadMap(UWorld* World) const;
	
	FOnLoaded OnLoadCallback;
};
