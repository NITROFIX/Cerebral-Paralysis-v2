// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/Guns/BaseWeapon.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "BasicWeaponComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CEREBRALPARALYSIS_V2_API UBasicWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName SocketName = "WeaponSocket";

	UPROPERTY()
	ABaseWeapon* CurrentBaseWeapon;
	
public:
	UBasicWeaponComponent();

	UFUNCTION(BlueprintCallable)
	void SetDirection(FRotator Direction) const;

protected:
	void DestroyWeapon(ABaseWeapon* Weapon) const;

	void SetCurrentWeapon(ABaseWeapon* Weapon) { CurrentBaseWeapon = Weapon; }

	template <typename T>
	T* SpawnWeapon(const TSubclassOf<ABaseWeapon> WeaponClass)
	{
		if (!GetWorld())
			return nullptr;

		ACharacter* Character = Cast<ACharacter>(GetOwner());
		if (!Character)
			return nullptr;

		T* Weapon = GetWorld()->SpawnActor<T>(WeaponClass);

		if (!Weapon)
			return nullptr;

		Weapon->SetOwner(Character);

		AttachWeaponToSocket(Weapon, Character->GetMesh(), SocketName);

		return Weapon;
	}

private:
	void AttachWeaponToSocket(ABaseWeapon* Weapon, USceneComponent* SceneComponent, const FName& Name) const;
};
