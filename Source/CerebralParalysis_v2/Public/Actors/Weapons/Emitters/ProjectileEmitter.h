// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Bullets/BaseBullet.h"
#include "Actors/Weapons/Emitters/SingleShotEmitter.h"
#include "ProjectileEmitter.generated.h"

class UWeaponObjectsFactorySubsystem;
/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API AProjectileEmitter : public ASingleShotEmitter
{
	GENERATED_BODY()

public:
	virtual void Emit(const FVector& Position, const FRotator Direction) override;
	
protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseBullet> Projectile;

	UPROPERTY(EditAnywhere)
	float Scatter;

	UPROPERTY()
	UWeaponObjectsFactorySubsystem* WeaponObjectsFactorySubsystem;

	virtual void BeginPlay() override;
	virtual void Construct();
	void SpawnBullet(const FVector& Position, FRotator Direction) const;
};
