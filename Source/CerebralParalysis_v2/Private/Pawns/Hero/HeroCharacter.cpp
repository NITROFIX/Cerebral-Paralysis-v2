// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Hero/HeroCharacter.h"

#include <string>

AHeroCharacter::AHeroCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
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

FVector AHeroCharacter::AdjustDirectionDependingOnObjectAngle(const FVector& Direction, const USceneComponent* TargetTransform) const
{
	const FRotator Rotation = TargetTransform->GetComponentRotation();
	const FRotator AngleAxis(0.0f, Rotation.Yaw, 0.0f);

	const FVector Forward = AngleAxis.RotateVector(FVector::ForwardVector);
	const FVector Right = AngleAxis.RotateVector(FVector::RightVector);

	const FVector MoveDirection = Forward * Direction.Y + Right * Direction.X;

	return MoveDirection;
}

