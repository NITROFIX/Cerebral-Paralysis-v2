// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Emitters/SingleShotEmitter.h"
#include "Actors/Weapons/Guns/BaseWeapon.h"
#include "Infrastructure/Subsystems/MusicSequencerSubsystem.h"
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

	void Construct();
	virtual void BeginPlay() override;
	void ForceFire();

public:
	void SetReloading();
	void StartFire();
	void StopFire();


private:
	UPROPERTY()
	UMusicSequencerSubsystem* MusicSequencerSubsystem;

	bool IsFiring;

	
	void ReloadFire();

	UFUNCTION()
	void OnMusicPlayerHit();
};
