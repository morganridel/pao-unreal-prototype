// Copyright : Morgan Ridel

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RollingBall.generated.h"

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

private:
	// Maximum velocity reachable by the ball
	UPROPERTY(EditDefaultsOnly)
	float MaxVelocity = 100;
	
};
