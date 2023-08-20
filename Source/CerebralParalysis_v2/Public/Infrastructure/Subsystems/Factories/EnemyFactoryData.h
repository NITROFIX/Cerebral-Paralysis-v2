// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyFactoryData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct CEREBRALPARALYSIS_V2_API FEnemyFactoryData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AActor> ZombieSoldier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AActor> Ancient;
};
