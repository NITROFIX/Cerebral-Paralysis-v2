// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Infrastructure/Subsystems/MusicSequencerSubsystem.h"
#include "MusicSequencePasser.generated.h"

UCLASS()
class CEREBRALPARALYSIS_V2_API AMusicSequencePasser : public AActor
{
	GENERATED_BODY()
	
public:	
	AMusicSequencePasser();

	UFUNCTION(BlueprintCallable)
	void TakeEasyHit() const;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UMusicSequencerSubsystem* MusicSequencer;
};
