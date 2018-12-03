// Copyright : Morgan Ridel

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RollingBall.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPowerUpDelegate);

class UPowerUp;

UCLASS()
class ROLLINGBALLPAO_API ARollingBall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARollingBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetBall(UPrimitiveComponent* BallToSet);

	UFUNCTION(BlueprintCallable)
	UPowerUp* GetPowerUp();

	UFUNCTION(BlueprintCallable)
	void SetPowerUp(UPowerUp* PowerUpToSet);

	/** Move the ball forward
	@param value - Strengh of the movement between -1 and 1
	*/
	UFUNCTION(BlueprintCallable)
	void RollForward(float value);

	/** Move the ball right
	@param value - Strengh of the movement between -1 and 1
	*/
	UFUNCTION(BlueprintCallable)
	void RollRight(float value);

	UFUNCTION(BlueprintCallable)
	bool UsePowerUp();

	UPrimitiveComponent* Ball = nullptr;

private:
	// Maximum force on the ball
	UPROPERTY(EditDefaultsOnly)
	float MaxRollingForce = 15000;

	UPROPERTY()
	UPowerUp* PowerUp = nullptr;

	UPROPERTY(BlueprintAssignable)
	FPowerUpDelegate OnNewPowerUp;

	UPROPERTY(BlueprintAssignable)
	FPowerUpDelegate OnRemovedPowerUp;

	

	
};
