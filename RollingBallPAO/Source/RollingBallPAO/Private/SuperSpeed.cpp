// Copyright : Morgan Ridel

#include "SuperSpeed.h"
#include <EngineGlobals.h>
#include <Engine/Engine.h>
#include "RollingBall.h"
#include "Components/PrimitiveComponent.h"

void USuperSpeed::Use()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Using SuperSpeed boost!"));

	ARollingBall* RollingBall = Cast<ARollingBall>(GetOwner());

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	auto CameraRotator = PlayerController->PlayerCameraManager->GetCameraRotation();
	CameraRotator.Pitch = 0;
	FVector CameraVector = CameraRotator.Vector();

	RollingBall->Ball->AddImpulse(CameraVector * 40000);
}
