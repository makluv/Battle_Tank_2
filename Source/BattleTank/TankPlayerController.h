// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h" // Must be the last include

// Forward declaration
class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimingComponentReference);

private: 
	void AimTowardsCrosshair(); //Start the tank moving the barrel so that a shot would hit where the crosshair interescts the world
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDireciton) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 10000000;
	UPROPERTY(EditAnywhere)
		float CrosshairXComponent = 0.5;
	UPROPERTY(EditAnywhere)
		float CrosshairYComponent = 0.3333333;
};
