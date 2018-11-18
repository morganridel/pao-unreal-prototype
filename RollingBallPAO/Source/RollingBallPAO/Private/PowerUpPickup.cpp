// Copyright : Morgan Ridel

#include "PowerUpPickup.h"
#include <EngineGlobals.h>
#include <Engine/Engine.h>
#include "PowerUp.h"
#include "RollingBall.h"


// Sets default values
APowerUpPickup::APowerUpPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}

// Called when the game starts or when spawned
void APowerUpPickup::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APowerUpPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APowerUpPickup::OnBeginOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Power up overlap!"));

	ARollingBall* RollingBall = Cast<ARollingBall>(OtherActor);
	if (!PowerUpClass) { 
		UE_LOG(LogTemp, Warning, TEXT("No PowerUpClass defined"));
		return false;
	}

	if (!RollingBall) {
		UE_LOG(LogTemp, Warning, TEXT("Overlap isn't with rolling ball"));
		return false;
	}


	UPowerUp* PowerUpComponent = NewObject<UPowerUp>(RollingBall, PowerUpClass, FName("Power Up"));
	PowerUpComponent->name = PowerUpName;
	//UE_LOG(LogTemp, Warning, TEXT("Component: %s"), *PowerUpComponent->GetReadableName());
	PowerUpComponent->RegisterComponent();

	
	RollingBall->PowerUp = PowerUpComponent;

	return true;

}

