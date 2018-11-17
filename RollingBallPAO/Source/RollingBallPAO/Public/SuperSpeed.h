// Copyright : Morgan Ridel

#pragma once

#include "CoreMinimal.h"
#include "PowerUp.h"
#include "SuperSpeed.generated.h"

/**
 * 
 */
UCLASS()
class ROLLINGBALLPAO_API USuperSpeed : public UPowerUp
{
	GENERATED_BODY()
	
	virtual void Use() override;
	
	
};
