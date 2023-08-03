#include "Actors/Utilities/CameraMover.h"
#include "Infrastructure/Subsystems/Factories/PlayerProviderSubsystem.h"

// Sets default values
UACameraMover::UACameraMover()
{
	bUseLerpMode = false;
	LerpSpeed = 5.0f; // Adjust this value to control the lerp speed (higher value means faster following)
	CameraOffset = FVector(0.f, 0.f, 0.f); // Default no displacement
}

// Called when the game starts or when spawned
void UACameraMover::BeginPlay()
{
	Super::BeginPlay();
	FindPlayer();
}

void UACameraMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!Player)
	{
		FindPlayer();
		return;
	}

	FVector TargetPosition = Player->GetActorLocation() + CameraOffset;
	FVector CurrentPosition = GetComponentLocation();

	if (bUseLerpMode)
	{
		MoveCameraLerp(DeltaTime, CurrentPosition, TargetPosition);
	}
	else
	{
		MoveCameraInstantly(TargetPosition);
	}
}

void UACameraMover::FindPlayer()
{
	if (!GetWorld())
		return;

	if (!GetWorld()->GetGameInstance())
		return;
	
	Player = GetWorld()->GetGameInstance()->GetSubsystem<UPlayerProviderSubsystem>()->GetPlayer();
}

void UACameraMover::MoveCameraLerp(float DeltaTime, const FVector& CurrentPosition, const FVector& TargetPosition)
{
	FVector NewPosition = FMath::Lerp(CurrentPosition, TargetPosition, FMath::Clamp(LerpSpeed * DeltaTime, 0.0f, 1.0f));
	SetWorldLocation(NewPosition);
}

void UACameraMover::MoveCameraInstantly(const FVector& TargetPosition)
{
	SetWorldLocation(TargetPosition);
}