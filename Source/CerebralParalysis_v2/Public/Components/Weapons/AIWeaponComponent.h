// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Components/Weapons/BasicWeaponComponent.h"
#include "AIWeaponComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CEREBRALPARALYSIS_V2_API UAIWeaponComponent : public UBasicWeaponComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Fire();
};
