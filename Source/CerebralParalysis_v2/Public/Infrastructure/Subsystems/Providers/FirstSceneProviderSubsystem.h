// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FirstSceneProviderSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API UFirstSceneProviderSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	FName FirstSceneName;

public:
	void SetFirstSceneName(const FName SceneName)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *SceneName.ToString());
		FirstSceneName = SceneName;
	}


	UFUNCTION(BlueprintCallable)
	FName GetFirstSceneName() const
	{
		return FirstSceneName;
	}
};
