// Copyright : Morgan Ridel

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUpPickup.generated.h"

class UPowerUp;

UCLASS(Abstract)
class ROLLINGBALLPAO_API APowerUpPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerUpPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Power Up")
	TSubclassOf<UPowerUp> PowerUpClass = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Power Up")
	FString PowerUpName = "Generic Power Up";

	UFUNCTION(BlueprintCallable)
	bool OnBeginOverlap(AActor* OtherActor);
};
