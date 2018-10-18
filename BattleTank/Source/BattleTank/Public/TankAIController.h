// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

	ATank* TheirTank;
	void LogOutput(ATank *AITank);
	ATank* PlayerTank;


private:
	virtual void BeginPlay() override;
	virtual void ATankAIController::Tick(float DeltaTime) override;
	ATank* GetPlayerTank() const;
	ATank* GetControlledTank() const;
	
};
