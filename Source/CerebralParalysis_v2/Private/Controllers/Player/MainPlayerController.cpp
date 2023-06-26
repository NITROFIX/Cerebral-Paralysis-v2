// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/Player/MainPlayerController.h"

#include "Pawns/Hero/HeroCharacter.h"

void AMainPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ACharacter* Character2 = GetCharacter();
	
	if (Character2 == nullptr)
		return;
	
	FHitResult FHit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_WorldStatic, true, FHit);

	AHeroCharacter* Character3;
	Character3 = Cast<AHeroCharacter>(Character2);

	Character3->SetLookRotation(FHit.Location);

	
	
	
}
