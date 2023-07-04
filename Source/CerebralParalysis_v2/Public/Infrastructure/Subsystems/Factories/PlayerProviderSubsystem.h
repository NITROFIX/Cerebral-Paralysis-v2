// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayerProviderSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API UPlayerProviderSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	UPROPERTY()
	APawn* Pawn;

public:

	UFUNCTION(BlueprintCallable)
	void SetPlayer(APawn* PlayerPawn)
	{
		Pawn = PlayerPawn;
	}

	UFUNCTION(BlueprintCallable)
	APawn* GetPlayer() const
	{
		return Pawn;
	}
	
};
