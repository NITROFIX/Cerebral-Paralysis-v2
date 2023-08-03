// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "CameraMover.generated.h"

UCLASS()
class CEREBRALPARALYSIS_V2_API UACameraMover : public UCameraComponent
{
	GENERATED_BODY()
	
public:
	UACameraMover();
	
	UFUNCTION(BlueprintCallable)
	void ChangeCameraMode(const bool UseLerpMode)
	{
		bUseLerpMode = UseLerpMode;
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Settings", meta = (EditCondition = "bUseLerpMode"))
	float LerpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Settings")
	FVector CameraOffset;

protected:
	virtual void BeginPlay() override;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Settings")
	bool bUseLerpMode;
	
private:
	UPROPERTY()
	APawn* Player;

	void FindPlayer();
	void MoveCameraLerp(float DeltaTime, const FVector& CurrentPosition, const FVector& TargetPosition);
	void MoveCameraInstantly(const FVector& TargetPosition);

};
