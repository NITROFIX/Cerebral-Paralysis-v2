// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Units/HealthComponent.h"

UHealthComponent::UHealthComponent()
{
}


void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

void UHealthComponent::TakeDamage(ETeam Team, float Damage)
{
	if (CanTakeDamage(Team) == false)
		return;

	CurrentHealth -= Damage;

	if (CurrentHealth < 0)
		Die();

	OnHealthChanged.Broadcast(CurrentHealth);
}

bool UHealthComponent::CanTakeDamage(ETeam Team)
{
	if (IsDead)
		return false;

	if (Team == HealthTeam)
		return false;

	return true;
}

void UHealthComponent::Die()
{
	IsDead = true;
	CurrentHealth = 0;
	OnDeath.Broadcast();
}
