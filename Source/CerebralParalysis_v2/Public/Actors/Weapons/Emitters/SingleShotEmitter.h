// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Emitters/BaseEmitter.h"
#include "SingleShotEmitter.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API ASingleShotEmitter : public ABaseEmitter
{
	GENERATED_BODY()

public:
	virtual void Emit(const FVector& Position, const FRotator Direction){}
	
};
