// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
#include "GameFramework/Actor.h"
#include "VFXPlayer.generated.h"

UCLASS()
class CEREBRALPARALYSIS_V2_API AVFXPlayer : public AActor
{
	GENERATED_BODY()
	
public:	
	AVFXPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
	UNiagaraSystem* VFX;
	
	UPROPERTY()
	UNiagaraComponent* NiagaraComponent;

	void Stop() const;

protected:
	virtual void BeginPlay() override;


};
