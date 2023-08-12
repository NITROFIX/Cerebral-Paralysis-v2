// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/Player/MainPlayerController.h"

#include "Components/CapsuleComponent.h"
#include "Pawns/Hero/HeroCharacter.h"

void AMainPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ACharacter* Character2 = GetCharacter();

	if (Character2 == nullptr)
		return;

	AHeroCharacter* Character3 = Cast<AHeroCharacter>(Character2);

	if (Character3)
	{
		FVector WorldLocation, WorldDirection;

		FVector2D MousePosition;
		GetMousePosition(MousePosition.X, MousePosition.Y);
		
		DeprojectScreenPositionToWorld(MousePosition.X, MousePosition.Y, WorldLocation, WorldDirection);

		const FVector PlaneIntersectionPoint = WorldLocation + (WorldDirection * ((GetCharacter()->GetActorLocation().Z - WorldLocation.Z) / WorldDirection.Z));

		Character3->SetLookRotation(PlaneIntersectionPoint);
	}
}
