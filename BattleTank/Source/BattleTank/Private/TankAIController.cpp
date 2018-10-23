// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = GetPlayerTank();
	LogOutput(PlayerTank);
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player
		auto PlayerTankLocation = PlayerTank->GetActorLocation();
		GetControlledTank()->AimAt(PlayerTankLocation);
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::LogOutput(ATank *PlayerTank)
{
	if (PlayerTank != nullptr)
	{
		FString PlayerTankName = PlayerTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("PlayerTankName variable is %s"), *PlayerTankName);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank is a nullptr"));
	}
}


ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}