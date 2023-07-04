// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Bullets/BaseBullet.h"
#include "Actors/Weapons/Guns/BaseWeapon.h"
#include "StaticData/ETeam.h"
#include "ProjectileWeapon.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API AProjectileWeapon : public ABaseWeapon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ABaseBullet> Projectile;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	double BulletSpread;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TraceMaxDistance = 1500;

private:
	FTimerHandle FireTimerHandle;
	
	virtual void TryFire() override;
	virtual void MakeShot() override;
	
	void CalculateTrace(FVector& TraceStart, FVector& TraceEnd) const;

	void ReloadFire();

};

