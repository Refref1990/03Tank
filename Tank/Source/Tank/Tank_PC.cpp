// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_PC.h"
#include "TankC.h"
#include "Engine/World.h"


ATank_PC::ATank_PC()
{
	LineTraceRange = 100000.f;
	crossX = 0.5;
	crossY = 0.3;
}

ATankC * ATank_PC::GetTank() const
{
	return Cast<ATankC>(GetPawn());
}

void ATank_PC::BeginPlay()
{
	Super::BeginPlay();
	auto CarroControllato = GetTank();

	if (!CarroControllato) return;

	if (CarroControllato)
	{
		UE_LOG(LogTemp, Warning, TEXT("trovato! %s"), *CarroControllato->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("trovato!"));
	}
}

void ATank_PC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mira();
}

void ATank_PC::Mira()
{
	if (!GetTank()) return;
	FVector HitLocation;
	if (TrovaVista(HitLocation))
	{
		GetTank()->AimAt(HitLocation);
	}
}

bool ATank_PC::TrovaVista(FVector & Location)
{
	//individuare la zona mirata
	int32 viewX, viewY;

	GetViewportSize(viewX, viewY);
	FVector2D Aimzone = FVector2D(viewX*crossX, viewY*crossY);

	//convertire tale zona in un vettore 3D
	FVector Direzione;
	TrovaDirezione(Aimzone, Direzione);

	//creare un linetrace in quella direzione
	FVector HitLocation;
	if ( !TrovaHit(Direzione, HitLocation) ) return false;
	Location = HitLocation;
	return true;
}

bool ATank_PC::TrovaDirezione(FVector2D ScreenLocation, FVector & Direzione)
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		Direzione
	);
}

bool ATank_PC::TrovaHit(FVector Direzione, FVector & HitLocation)
{
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	FHitResult Hit;

	FVector Endline = StartLocation + Direzione * LineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, Endline, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = Hit.Location;
		return true;
	}

	HitLocation = FVector(0, 0, 0);
	return false;
}
