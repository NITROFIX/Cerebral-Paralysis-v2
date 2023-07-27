// Cerebral Paralysis... Think twice ;)


#include "Actors/Weapons/Guns/Enemies/AncientGunWeapon.h"

#include "Actors/Weapons/Emitters/SingleShotEmitter.h"
#include "StaticData/EAIAttackTypes.h"

void AAncientGunWeapon::BeginPlay()
{
	Super::BeginPlay();

	EasyHitEmitter = Cast<ASingleShotEmitter>(GetWorld()->SpawnActor(EasyHitEmitterClass));
	EasyHitEmitter->SetOwner(GetOwner());

	MediumHitEmitter = Cast<ASingleShotEmitter>(GetWorld()->SpawnActor(MediumHitEmitterClass));
	MediumHitEmitter->SetOwner(GetOwner());
}

void AAncientGunWeapon::Fire(EAIAttackType AttackType) 
{
	if (AttackType == EAIAttackType::Easy)
		EasyHitEmitter->Emit(GetMuzzleTransform().GetLocation(), FireDirection);
	else if (AttackType == EAIAttackType::Medium)
		MediumHitEmitter->Emit(GetMuzzleTransform().GetLocation(), FireDirection);
}
