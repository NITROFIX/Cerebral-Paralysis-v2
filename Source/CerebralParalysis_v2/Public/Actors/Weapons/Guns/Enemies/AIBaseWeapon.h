// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Guns/BaseWeapon.h"
#include "AIBaseWeapon.generated.h"

enum class EAIAttackType : uint8;
/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API AAIBaseWeapon : public ABaseWeapon
{
	GENERATED_BODY()

public:
	virtual void Fire(EAIAttackType AttackType) {}
};
