// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Guns/BaseWeapon.h"
#include "Components/ActorComponent.h"
#include "BasicWeaponComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CEREBRALPARALYSIS_V2_API UBasicWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UBasicWeaponComponent();

	UFUNCTION(BlueprintCallable)
	void SetDirection(FRotator Direction) const;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void SpawnWeapon();

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName SocketName = "WeaponSocket";

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<ABaseWeapon> WeaponClass;

	UPROPERTY()
	ABaseWeapon* CurrentWeapon;

private:
	void AttachWeaponToSocket(ABaseWeapon* Weapon, USceneComponent* SceneComponent, const FName& Name) const;
};
