// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Bullets/BaseBullet.h"
#include "Actors/Weapons/Emitters/SingleShotEmitter.h"
#include "ProjectileEmitter.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API AProjectileEmitter : public ASingleShotEmitter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseBullet> Projectile;

public:
	virtual void Emit(const FVector& Position, const FRotator Direction) override;

protected:
	void SpawnBullet(const FVector& Position, FRotator Direction) const;
};
