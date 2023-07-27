// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Guns/Player/PlayerPistol.h"
#include "Components/Weapons/BasicWeaponComponent.h"
#include "PlayerWeaponComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CEREBRALPARALYSIS_V2_API UPlayerWeaponComponent : public UBasicWeaponComponent
{
	GENERATED_BODY()

	UPlayerWeaponComponent();

protected:
	UPROPERTY()
	APlayerPistol* PistolWeapon;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APlayerPistol> WeaponClass;
	
	bool IsFiring;

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:
	UFUNCTION(BlueprintCallable)
	void StartFire();

	UFUNCTION(BlueprintCallable)
	void StopFire();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
