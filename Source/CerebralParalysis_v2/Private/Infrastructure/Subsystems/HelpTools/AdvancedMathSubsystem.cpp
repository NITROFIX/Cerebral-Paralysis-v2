// Cerebral Paralysis... Think twice ;)


#include "Infrastructure/Subsystems/HelpTools/AdvancedMathSubsystem.h"

FVector UAdvancedMathSubsystem::FindRandomPointInOverlap(const FVector& Circle1Center, float Circle1Radius,
                                                         const FVector& Circle2Center, float Circle2Radius)
{
	float Distance = FVector::Dist(Circle1Center, Circle2Center);

	// Check if the circles do not overlap
	if (Distance > Circle1Radius + Circle2Radius)
	{
		return FVector::ZeroVector;
	}

	// Find intersection points (if they exist)
	if (Distance <= FMath::Abs(Circle1Radius - Circle2Radius))
	{
		return FVector::ZeroVector;
	}

	const float D1 = (Circle1Radius * Circle1Radius - Circle2Radius * Circle2Radius + Distance * Distance) / (2 *
		Distance);
	const float D2 = Distance - D1;
	const FVector P1 = ((D1 * Circle2Center + D2 * Circle1Center) / Distance);
	const FVector P2 = ((D2 * Circle2Center + D1 * Circle1Center) / Distance);

	const float X_Min = FMath::Max(P1.X, P2.X);
	const float X_Max = FMath::Min(P1.X, P2.X);
	const float Y_Min = FMath::Max(P1.Y, P2.Y);
	const float Y_Max = FMath::Min(P1.Y, P2.Y);

	const float Random_X = FMath::RandRange(X_Min, X_Max);
	const float Random_Y = FMath::RandRange(Y_Min, Y_Max);

	return FVector(Random_X, Random_Y, 0.f);
}

FVector UAdvancedMathSubsystem::FindRandomPointByDotProduct(FVector FirstPoint, FVector SecondPoint)
{
	FVector OptimizedFirstPoint = FirstPoint;

	OptimizedFirstPoint.Z = 0;
	SecondPoint.Z = 0;

	FVector Distance = OptimizedFirstPoint - SecondPoint;
	FVector Direction = Distance;
	Direction.Normalize();

	FVector RandomVector = GetRandomNormalizedVector();
	UE_LOG(LogTemp, Warning, TEXT("End Distanation: %s"), *((RandomVector).ToString()))
	float DotProduct = FVector::DotProduct(Direction, RandomVector);
	float AbsDotProduct = FMath::Abs(DotProduct);
	
	float StrafePowerScale = AbsDotProduct;
	StrafePowerScale *= -1;
	StrafePowerScale += 1;

	float TractionPower = 1;

	if (DotProduct < 0)
	{
		TractionPower = -DotProduct * 1000;
	}

	RandomVector *= StrafePowerScale;
	RandomVector *= TractionPower;
	RandomVector *= 1000;


	return RandomVector + FirstPoint;
}

FVector UAdvancedMathSubsystem::GetRandomNormalizedVector() const
{
	FVector2d RandomVector2d;
	FVector RandomVector;

	
	RandomVector2d.X = FMath::RandRange(-100, 100);
	RandomVector2d.Y = FMath::RandRange(-100, 100);
	RandomVector2d.Normalize();

	RandomVector.X = RandomVector2d.X;
	RandomVector.Y = RandomVector2d.Y;
	RandomVector.Z = 0;

	return RandomVector;
}
