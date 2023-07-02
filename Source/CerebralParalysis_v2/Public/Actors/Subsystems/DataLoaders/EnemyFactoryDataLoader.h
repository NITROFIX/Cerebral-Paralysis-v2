// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Actors/Subsystems/DataLoader.h"
#include "Infrastructure/Subsystems/Factories/EnemyFactoryData.h"
#include "EnemyFactoryDataLoader.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API AEnemyFactoryDataLoader : public ADataLoader
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FEnemyFactoryData Data;

	virtual void LoadData() override;
	virtual void BeginPlay() override;
};
