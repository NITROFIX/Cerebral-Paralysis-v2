// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "AIBaseWeapon.h"
#include "Actors/Weapons/Guns/BaseWeapon.h"
#include "StaticData/EAIAttackTypes.h"
#include "AncientGunWeapon.generated.h"

class ASingleShotEmitter;
/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API AAncientGunWeapon : public AAIBaseWeapon
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASingleShotEmitter> EasyHitEmitterClass;

	UPROPERTY()
	ASingleShotEmitter* EasyHitEmitter;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASingleShotEmitter> MediumHitEmitterClass;

	UPROPERTY()
	ASingleShotEmitter* MediumHitEmitter;

protected:
	virtual void BeginPlay() override;

	virtual void Fire(EAIAttackType AttackType) override;
	
};
