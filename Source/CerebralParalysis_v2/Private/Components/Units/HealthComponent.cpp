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

void UHealthComponent::TakeDamage(float Damage)
{
	if (IsDead)
		return;

	CurrentHealth -= Damage;

	if (CurrentHealth < 0)
		Die();
	
	OnHealthChanged.Broadcast(CurrentHealth);
}

void UHealthComponent::Die()
{
	IsDead = true;
	CurrentHealth = 0;
	OnDeath.Broadcast();
}
