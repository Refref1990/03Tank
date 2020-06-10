// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_AIC.h"
#include "TankC.h"
#include "Tank_PC.h"
#include "Engine/World.h"

ATankC * ATank_AIC::GetPlayerTank() const
{

	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	return Cast<ATankC> (controller->GetPawn());
}

ATank_AIC::ATank_AIC()
{
	Timer = FMath::FRandRange(3.f, 6.f);

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

	Super::Tick(DeltaTime);
	if (GetPlayerTank()&& GetTank())
	{

		GetTank()->AimAt(GetPlayerTank()->GetActorLocation());

		if (Timer > 0) Timer -= DeltaTime;
		else

		{
		GetTank()->Spara();
		Timer = FMath::FRandRange(3.f, 6.f);

		}



			
	}
}
