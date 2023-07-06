// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayerFactorySubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API UPlayerFactorySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	APawn* SpawnPlayer(const TSubclassOf<APawn> DefaultPawnClass, const AActor* StartSpot) const;
	
};
