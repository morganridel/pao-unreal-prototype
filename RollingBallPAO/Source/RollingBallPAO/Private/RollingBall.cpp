// Copyright : Morgan Ridel

#include "RollingBall.h"


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
	UE_LOG(LogTemp, Warning, TEXT("Rolling forward value: %f"), value);
}

void ARollingBall::RollRight(float value)
{
	UE_LOG(LogTemp, Warning, TEXT("Rolling right value: %f"), value);
}

