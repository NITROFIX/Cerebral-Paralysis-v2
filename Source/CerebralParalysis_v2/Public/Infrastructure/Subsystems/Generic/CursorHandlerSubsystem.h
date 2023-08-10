// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CursorHandlerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API UCursorHandlerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ShowCursor(APlayerController* PlayerController) const;

	UFUNCTION(BlueprintCallable)
	void HideCursor(APlayerController* PlayerController) const;
};
