// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Emitters/SingleShotEmitter.h"
#include "Actors/Weapons/Guns/BaseWeapon.h"
#include "PlayerPistol.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API APlayerPistol : public ABaseWeapon
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASingleShotEmitter> EmitterClass;

	UPROPERTY(EditDefaultsOnly)
	float ReloadTime;

	FTimerHandle FireTimerHandle;

	bool CanFire = true;
	
	UPROPERTY()
	ASingleShotEmitter* Emitter;

	virtual void BeginPlay() override;
	
public:
	void SetReloading();
	void Fire();

private:
	void ReloadFire();
};
