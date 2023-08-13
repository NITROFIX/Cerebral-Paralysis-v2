// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Emitters/SingleShotEmitter.h"
#include "StaticData/ETeam.h"
#include "RaycastEmitter.generated.h"

class UNiagaraSystem;
class UWeaponFXComponent;
/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API ARaycastEmitter : public ASingleShotEmitter
{
	GENERATED_BODY()

	ARaycastEmitter();
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UWeaponFXComponent* WeaponFXComponent2;



	virtual void Emit(const FVector& Position, const FRotator Direction) override;

protected:
	UPROPERTY(EditDefaultsOnly)
	float DamageAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ETeam Team;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TraceMaxDistance = 1500;

	UPROPERTY(EditDefaultsOnly)
	double BulletSpread;

	UPROPERTY(EditDefaultsOnly)
	UNiagaraSystem* TraceFX;

	UPROPERTY(EditDefaultsOnly)
	FString TraceTargetName = "TraceTarget";


private:
	void CalculateTrace(const FVector& StartPosition, FRotator Direction, FVector& TraceStart, FVector& TraceEnd) const;
	void Raycast(FVector TraceStart, FVector TraceEnd, FHitResult& HitResult) const;
	void Damage(FHitResult HitResult) const;
	void ReloadFire();
	void SpawnTraceFX(const FVector& TraceStart, const FVector& TraceEnd) const;
};
