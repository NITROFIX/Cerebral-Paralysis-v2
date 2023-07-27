// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Emitters/ProjectileEmitter.h"
#include "MultipleProjectileEmitter.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API AMultipleProjectileEmitter : public AProjectileEmitter
{
	GENERATED_BODY()

	virtual void Emit(const FVector& Position, const FRotator Direction) override;
	
};
