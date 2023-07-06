// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
#include "Actors/VFX/VFXPlayer.h"
#include "Components/SceneComponent.h"
#include "VFXTrailPlayer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CEREBRALPARALYSIS_V2_API UVFXTrailPlayer : public USceneComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	bool AutoPlay;

	UPROPERTY(EditDefaultsOnly)
	UClass* TrailActor;

	UPROPERTY()
	AVFXPlayer* CurrentTrailActor;

public:
	UVFXTrailPlayer();
	
	void SpawnSystem();

	UFUNCTION(BlueprintCallable)
	void DetachSystem() const;

	UFUNCTION(BlueprintCallable)
	void DestroyTrailActor();
	
protected:
	virtual void BeginPlay() override;
		
};
