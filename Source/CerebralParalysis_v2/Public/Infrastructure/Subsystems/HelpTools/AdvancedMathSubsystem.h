// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AdvancedMathSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API UAdvancedMathSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FVector FindRandomPointInOverlap(const FVector& Circle1Center, float Circle1Radius, const FVector& Circle2Center, float Circle2Radius);

	UFUNCTION(BlueprintCallable)
	FVector FindRandomPointByDotProduct(FVector FirstPoint, FVector SecondPoint);
	
	FVector GetRandomNormalizedVector() const;
};
