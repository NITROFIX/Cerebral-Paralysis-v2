// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Subsystems/MusicSequencePasser.h"
#include "Infrastructure/Subsystems/MusicSequencerSubsystem.h"

AMusicSequencePasser::AMusicSequencePasser()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMusicSequencePasser::BeginPlay()
{
	Super::BeginPlay();

	MusicSequencer = GetGameInstance()->GetSubsystem<UMusicSequencerSubsystem>();
}

void AMusicSequencePasser::TakeEasyHit() const
{
	MusicSequencer->TakeEasyHit();
}

void AMusicSequencePasser::TakeMediumHit() const
{
	MusicSequencer->TakeMediumHit();
}
