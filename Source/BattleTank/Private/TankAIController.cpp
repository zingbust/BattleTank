// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// TODO Move towards the player

	auto ThisTank = Cast<ATank>(GetPawn());
	auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	PlayerTank = Cast<ATank>(PlayerPawn);
	// Aim towards the player
	if (PlayerTank)
	{ 
		auto PlayerTankLocation = PlayerTank->GetActorLocation();
		ThisTank->AimAt(PlayerTankLocation);
		ThisTank->Fire(); // TODO Don't fire every frame
	}
}