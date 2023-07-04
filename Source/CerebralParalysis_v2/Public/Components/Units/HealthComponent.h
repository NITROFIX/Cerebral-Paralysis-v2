// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StaticData/ETeam.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, Health);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CEREBRALPARALYSIS_V2_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnDeath OnDeath;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ETeam HealthTeam;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(ETeam Team, float Damage);

	UFUNCTION(BlueprintCallable)
	bool CanTakeDamage(ETeam Team);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	bool IsDead = false;

	virtual void BeginPlay() override;

private:
	void Die();
};
