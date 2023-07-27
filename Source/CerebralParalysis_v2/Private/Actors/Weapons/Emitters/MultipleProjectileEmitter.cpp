// Cerebral Paralysis... Think twice ;)


#include "Actors/Weapons/Emitters/MultipleProjectileEmitter.h"

void AMultipleProjectileEmitter::Emit(const FVector& Position, const FRotator Direction)
{
	if (!GetWorld())
		return;

	// Fire the center bullet in the current direction
	SpawnBullet(Position, Direction);

	// Calculate deviations for the two additional bullets
	float DeviationAngle = 15.0f; // Adjust this angle as needed for the desired deviation
	float LeftDeviationAngle = DeviationAngle;
	float RightDeviationAngle = -DeviationAngle;

	// Add random offsets for the additional bullets
	float MaxOffset = 50.0f; // Adjust this value to control the maximum offset
	FVector Offset1 = FVector(FMath::FRandRange(-MaxOffset, MaxOffset), FMath::FRandRange(-MaxOffset, MaxOffset), FMath::FRandRange(-MaxOffset, MaxOffset));
	FVector Offset2 = FVector(FMath::FRandRange(-MaxOffset, MaxOffset), FMath::FRandRange(-MaxOffset, MaxOffset), FMath::FRandRange(-MaxOffset, MaxOffset));

	// Fire the first additional bullet deviated to the left
	FRotator LeftDeviationDirection = Direction + FRotator(0.0f, LeftDeviationAngle, 0.0f);
	SpawnBullet(Position + Offset1, LeftDeviationDirection);

	// Fire the second additional bullet deviated to the right
	FRotator RightDeviationDirection = Direction + FRotator(0.0f, RightDeviationAngle, 0.0f);
	SpawnBullet(Position + Offset2, RightDeviationDirection);

	
}
