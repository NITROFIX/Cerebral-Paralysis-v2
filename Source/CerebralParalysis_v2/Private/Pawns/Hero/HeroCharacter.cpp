// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Hero/HeroCharacter.h"

#include <string>

AHeroCharacter::AHeroCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UACameraMover>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

	WeaponComponent = CreateDefaultSubobject<UPlayerWeaponComponent>("Weapon Component");
}

void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AHeroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveVector = AdjustDirectionDependingOnObjectAngle(MoveVector, CameraComponent);
	AddMovementInput(MoveVector, SpeedAmount);
	WeaponComponent->SetDirection(LatestRotation);

	UpdateTeleportVisualization();

	if (bIsDashKeyPressed)
		UpdateTeleportTime();
}

float AHeroCharacter::GetMovementDirection() const
{
	const auto VelocityNormal = GetVelocity().GetSafeNormal();
	const double AngleBetween = FMath::Acos(FVector::DotProduct(GetActorForwardVector(), VelocityNormal));
	const auto CrossProduct = FVector::CrossProduct(GetActorForwardVector(), VelocityNormal);
	return FMath::RadiansToDegrees(AngleBetween) * FMath::Sign(CrossProduct.Z);
}

void AHeroCharacter::SetLookRotation(FVector_NetQuantize Vector)
{
	Vector.Z = GetActorLocation().Z;
	const FVector FinalVector = Vector - GetActorLocation();
	const FRotator NewRotation = FinalVector.Rotation();
	LatestRotation = NewRotation;
	RootComponent->SetWorldRotation(NewRotation);
}


void AHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Horizontal", this, &AHeroCharacter::MoveHorizontal);
	PlayerInputComponent->BindAxis("Vertical", this, &AHeroCharacter::MoveVertical);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AHeroCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AHeroCharacter::StopFire);
	PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &AHeroCharacter::OnTeleportPressed);
	PlayerInputComponent->BindAction("Dash", IE_Released, this, &AHeroCharacter::OnTeleportReleased);
}

void AHeroCharacter::StartFire()
{
	WeaponComponent->StartFire();
}

void AHeroCharacter::StopFire()
{
	WeaponComponent->StopFire();
}


void AHeroCharacter::MoveHorizontal(const float Amount)
{
	MoveVector.X = Amount;
}

void AHeroCharacter::MoveVertical(const float Amount)
{
	MoveVector.Y = Amount;
}

FVector AHeroCharacter::AdjustDirectionDependingOnObjectAngle(const FVector& Direction,
                                                              const USceneComponent* TargetTransform) const
{
	const FRotator Rotation = TargetTransform->GetComponentRotation();
	const FRotator AngleAxis(0.0f, Rotation.Yaw, 0.0f);

	const FVector Forward = AngleAxis.RotateVector(FVector::ForwardVector);
	const FVector Right = AngleAxis.RotateVector(FVector::RightVector);

	const FVector MoveDirection = Forward * Direction.Y + Right * Direction.X;

	return MoveDirection;
}

void AHeroCharacter::TeleportInDirection(const float TeleportDistance)
{
	if (TeleportDistance <= 0.0f)
		return;

	const FVector NewLocation = GetActorLocation() + GetActorForwardVector() * TeleportDistance;
	SetActorLocation(NewLocation);
}

void AHeroCharacter::OnTeleportPressed()
{
	bIsDashKeyPressed = true;
	TeleportTime = 0.0f;
}

void AHeroCharacter::OnTeleportReleased()
{
	bIsDashKeyPressed = false;
	GetWorldTimerManager().ClearTimer(TeleportTimerHandle);
	const float TeleportDistance = FMath::Clamp(TeleportTime * TeleportDistanceMultiplier, 0.0f, MaxTeleportDistance);
	// Adjust the multiplier to control the teleport speed.
	TeleportInDirection(TeleportDistance);
}

void AHeroCharacter::UpdateTeleportTime()
{
	TeleportTime += TeleportChangeSpeed;
}

void AHeroCharacter::UpdateTeleportVisualization()
{
	if (!bIsDashKeyPressed)
		return;
	
	// Calculate the teleport distance based on how long the Dash key was held.
	float TeleportDistance = FMath::Clamp(TeleportTime * TeleportDistanceMultiplier, 0.0f, MaxTeleportDistance);

	// Get the destination location where the player will teleport.
	FVector DestinationLocation = GetActorLocation() + GetActorForwardVector() * TeleportDistance;

	// Calculate the circle's up vector as perpendicular to the player's forward vector and the world up vector.
	
	// Calculate the circle's up vector as perpendicular to the player's forward vector and the world up vector.
	FVector CircleUpVector = FVector::VectorPlaneProject(FVector::UpVector, GetActorForwardVector()).GetSafeNormal();

	// Draw the teleportation indicator (debug circle) at the destination location with the correct orientation.
	FVector Center = DestinationLocation;
	float Radius = 50.0f; // Adjust the radius of the circle as needed.
	int32 NumPoints = 36; // Number of points used to approximate the circle (higher values give smoother circles).

	DrawDebugCircle(GetWorld(), Center, Radius, NumPoints, FColor::Blue, false, -1, 0, 5.0f, CircleUpVector); // Pass the circle's up vector as the last argument.the circle's up vector as the last argument.
	// Draw the teleportation line (debug line) connecting the player to the destination.
	DrawDebugLine(GetWorld(), GetActorLocation(), DestinationLocation, FColor::Blue, false, -1, 0, 5.0f);
	
	// Note: The last three parameters (0, 5.0f) specify the line thickness and duration for both debug shapes. You can adjust these values as needed.
}
