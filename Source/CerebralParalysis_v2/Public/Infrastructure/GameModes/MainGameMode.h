// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API AMainGameMode : public AGameMode
{
	GENERATED_BODY()

	virtual APawn* SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot) override;
};
