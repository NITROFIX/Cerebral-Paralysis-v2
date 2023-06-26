// Fill out your copyright notice in the Description page of Project Settings.


#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"

#include "Infrastructure/States/LoadLevelState/ULoadLevelState.h"
#include "Kismet/GameplayStatics.h"
#include "Microsoft/AllowMicrosoftPlatformTypes.h"
#include "StaticData/LevelNames.h"

void ULoadLevelSubsystem::Construct(UWorld* NewWorld)
{
	CurrentWorld = NewWorld;
}

void ULoadLevelSubsystem::OnPostLoadMap(UWorld* World)
{
	OnLoadCallback.Execute(World);
}


void ULoadLevelSubsystem::LoadLevel(const FName& SceneName, FOnLoaded Action)
{
	UGameplayStatics::OpenLevel(CurrentWorld, SceneName);

	OnLoadCallback = Action;
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &ULoadLevelSubsystem::OnPostLoadMap);
}
