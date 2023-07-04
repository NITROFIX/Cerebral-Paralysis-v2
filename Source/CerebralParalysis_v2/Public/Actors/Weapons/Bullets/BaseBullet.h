// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "StaticData/ETeam.h"
#include "BaseBullet.generated.h"

UCLASS()
class CEREBRALPARALYSIS_V2_API ABaseBullet : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere)
	ETeam Team;


public:
	ABaseBullet();

	UFUNCTION(BlueprintCallable)
	void SetDirection(FVector Direction) const;

	UFUNCTION(BlueprintCallable)
	void SetTeam(const ETeam NewTeam)
	{
		Team = NewTeam;
	}

	UFUNCTION(BlueprintCallable)
	ETeam GetTeam() const
	{
		return Team;
	}

protected:
	virtual void BeginPlay() override;
};
