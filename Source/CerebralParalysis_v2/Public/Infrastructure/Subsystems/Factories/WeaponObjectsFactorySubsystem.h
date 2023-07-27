// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WeaponObjectsFactorySubsystem.generated.h"

class ABaseBullet;
/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API UWeaponObjectsFactorySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	ABaseBullet* CreateBullet(TSubclassOf<ABaseBullet> Projectile, const FVector& Position, FRotator Direction) const;

private:
	void CalculateTrace(const FVector& TraceStart, FRotator Direction, FVector& TraceEnd) const;
};
