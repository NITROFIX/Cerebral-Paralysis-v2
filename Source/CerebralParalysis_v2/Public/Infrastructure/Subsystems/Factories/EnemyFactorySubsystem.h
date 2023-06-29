// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "EnemyFactoryData.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EnemyFactorySubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API UEnemyFactorySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	FEnemyFactoryData Data;

public:
	void Construct(const FEnemyFactoryData NewData)
	{
		UE_LOG(LogTemp, Warning, TEXT("Data Loaded"));
		Data = NewData;
	}
};
