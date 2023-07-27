// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Guns/Enemies/AncientGunWeapon.h"
#include "Components/Weapons/BasicWeaponComponent.h"
#include "StaticData/EAIAttackTypes.h"
#include "AIWeaponComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CEREBRALPARALYSIS_V2_API UAIWeaponComponent : public UBasicWeaponComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AAIBaseWeapon> WeaponClass;

private:
	UPROPERTY()
	AAIBaseWeapon* CurrentWeapon;
	
public:
	UFUNCTION(BlueprintCallable)
	void Fire(EAIAttackType AttackType);
};
