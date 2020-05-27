// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_AIC.h"
#include "TankC.h"
#include "Engine/World.h"

ATankC * ATank_AIC::GetPlayerTank() const
{

	auto controller = GetWorld()->GetFirstPlayerController();
	return Cast<ATankC> (controller->GetPawn());
}

ATankC * ATank_AIC::GetTank() const
{
	return Cast<ATankC>(GetPawn());
}

void ATank_AIC::BeginPlay()
{
	auto CarroControllato = GetTank();
	auto CarroNemico = GetPlayerTank();

	if (!CarroControllato || !CarroNemico) return;

	if (CarroControllato)
	{
		UE_LOG(LogTemp, Warning, TEXT("trovato! %s"), *CarroControllato->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("trovato!"));
	}
}

void ATank_AIC::Tick(float DeltaTime)
{
	if (GetPlayerTank())
	{

		GetTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}
