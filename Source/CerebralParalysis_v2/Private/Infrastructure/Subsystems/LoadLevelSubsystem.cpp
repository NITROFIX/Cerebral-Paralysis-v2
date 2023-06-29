// Fill out your copyright notice in the Description page of Project Settings.


#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"
#include "Infrastructure/States/LoadLevelState/ULoadLevelState.h"
#include "Kismet/GameplayStatics.h"


void ULoadLevelSubsystem::LoadLevel(const UWorld* CurrentWorld, const FName& SceneName, const FOnLoaded Action)
{
	UGameplayStatics::OpenLevel(CurrentWorld, SceneName);

	OnLoadCallback = Action;
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &ULoadLevelSubsystem::OnPostLoadMap);
}

void ULoadLevelSubsystem::OnPostLoadMap(UWorld* World) const
{
	OnLoadCallback.Execute(World);
}
