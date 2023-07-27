// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MusicSequencerSubsystem.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEasyHit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMediumHit);

UCLASS()
class CEREBRALPARALYSIS_V2_API UMusicSequencerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnEasyHit OnEasyHit;

	void TakeEasyHit() const
	{
		OnEasyHit.Broadcast();
	}

	UPROPERTY(BlueprintAssignable)
	FOnMediumHit OnMediumHit;

	void TakeMediumHit() const
	{
		OnMediumHit.Broadcast();
	}
};
