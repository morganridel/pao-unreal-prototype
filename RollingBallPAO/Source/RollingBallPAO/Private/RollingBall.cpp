// Copyright : Morgan Ridel

#include "RollingBall.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "PowerUp.h"
#include <EngineGlobals.h>
#include <Engine/Engine.h>


// Sets default values
ARollingBall::ARollingBall()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARollingBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARollingBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + GetVelocity(), FColor::Green, false, (-1.0F), 0, 10);
	//UE_LOG(LogTemp, Warning, TEXT("Ball Velocity: %f"), GetVelocity().Size());

	FString PowerUpName = "";
	if (PowerUp) {
		PowerUpName = PowerUp->GetReadableName();
	}
	//UE_LOG(LogTemp, Warning, TEXT("Power Up : %s"), *PowerUpName);
}

// Called to bind functionality to input
void ARollingBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARollingBall::SetBall(UPrimitiveComponent * BallToSet)
{
	Ball = BallToSet;
}

void ARollingBall::RollForward(float value)
{

	if (!Ball) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("No ball set"));
		return; 
	}
	

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	auto CameraRotator = PlayerController->PlayerCameraManager->GetCameraRotation();
	CameraRotator.Pitch = 0;
	FVector CameraVector = CameraRotator.Vector();

	FVector ForwardVector = GetActorForwardVector();
	ForwardVector = CameraVector;
	float ForceStrength = value * MaxRollingForce;
	FVector ForceLocation = GetActorLocation();

	DrawDebugLine(GetWorld(), ForceLocation, ForceLocation+ForwardVector*2*ForceStrength, FColor::Red, false, (-1.0F), 0, 10);

	FVector Force = ForwardVector * ForceStrength;
	Ball->AddForceAtLocation(Force, ForceLocation);


	
}

void ARollingBall::RollRight(float value)
{
	if (!Ball)
	{
		UE_LOG(LogTemp, Warning, TEXT("No ball set"));
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	auto CameraRotator = PlayerController->PlayerCameraManager->GetCameraRotation();
	CameraRotator.Pitch = 0;
	CameraRotator.Yaw += 90;
	FVector CameraVector = CameraRotator.Vector();

	FVector RightVector = GetActorRightVector();
	RightVector = CameraVector;
	float ForceStrength = value * MaxRollingForce;
	FVector ForceLocation = GetActorLocation();

	DrawDebugLine(GetWorld(), ForceLocation, ForceLocation + RightVector * 2 * ForceStrength, FColor::Red, false, (-1.0F), 0, 10);

	FVector Force = RightVector * ForceStrength;
	Ball->AddForceAtLocation(Force, ForceLocation);
}

bool ARollingBall::UsePowerUp()
{
	if (!PowerUp) { 
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No power up possessed"));
		return false;
	}

	PowerUp->Use();
	PowerUp = nullptr;
	return true;
}

