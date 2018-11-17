// Copyright : Morgan Ridel

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PowerUp.generated.h"


UCLASS(Abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROLLINGBALLPAO_API UPowerUp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPowerUp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void Use() PURE_VIRTUAL(UPowerUp::Use, ;);
		
	
};
