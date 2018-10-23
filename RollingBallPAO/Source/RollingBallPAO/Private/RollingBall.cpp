// Copyright : Morgan Ridel

#include "RollingBall.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


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

}

// Called to bind functionality to input
void ARollingBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARollingBall::RollForward(float value)
{
	

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	auto CameraRotator = PlayerController->PlayerCameraManager->GetCameraRotation();
	CameraRotator.Pitch = 0;
	FVector CameraVector = CameraRotator.Vector();

	FVector ForwardVector = GetActorForwardVector();
	ForwardVector = CameraVector;
	float ForceStrength = value * MaxVelocity;
	FVector ForceLocation = GetActorLocation();

	UE_LOG(LogTemp, Warning, TEXT("Rolling forward vector: %s"), *ForwardVector.ToString());

	DrawDebugLine(GetWorld(), ForceLocation, ForceLocation+ForwardVector*2*ForceStrength, FColor::Red, false, (-1.0F), 0, 10);

	FVector Force = ForwardVector * ForceStrength;
	UPrimitiveComponent* BallRoot = Cast<UPrimitiveComponent>(GetRootComponent());
	BallRoot->AddForceAtLocation(Force, ForceLocation);


	
}

void ARollingBall::RollRight(float value)
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	auto CameraRotator = PlayerController->PlayerCameraManager->GetCameraRotation();
	CameraRotator.Pitch = 0;
	CameraRotator.Yaw += 90;
	FVector CameraVector = CameraRotator.Vector();

	FVector RightVector = GetActorRightVector();
	RightVector = CameraVector;
	float ForceStrength = value * MaxVelocity;
	FVector ForceLocation = GetActorLocation();

	DrawDebugLine(GetWorld(), ForceLocation, ForceLocation + RightVector * 2 * ForceStrength, FColor::Red, false, (-1.0F), 0, 10);

	FVector Force = RightVector * ForceStrength;
	UPrimitiveComponent* BallRoot = Cast<UPrimitiveComponent>(GetRootComponent());
	BallRoot->AddForceAtLocation(Force, ForceLocation);
}

