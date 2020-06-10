// Fill out your copyright notice in the Description page of Project Settings.


#include "TankC.h"
#include "Aiming_Component.h"
#include "Proiettile.h"
#include "MeshTorretta.h"

// Sets default values
ATankC::ATankC()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Aiming = CreateDefaultSubobject <UAiming_Component>(TEXT("Aiming"));
	ReloadTime = 2.f;
	Reload = ReloadTime;
}

// Called when the game starts or when spawned
void ATankC::BeginPlay()
{
	Super::BeginPlay();
	Reload = 0;
	
}

void ATankC::SetCannone(UMeshTorretta * Cannon)
{
	Cannone = Cannon;
}

void ATankC::AimAt(FVector HitLocation)
{
	Aiming->AimAt(HitLocation);

	
}

void ATankC::Spara()
{
	if (Reload <= 0)
	{
		UE_LOG(LogTemp, Error, (TEXT("Sparo a Salve!!")));
		auto Bullet = GetWorld()->SpawnActor<AProiettile>(
			Projectile,
			Cannone->GetSocketLocation(FName("Proiettile")),
			Cannone->GetSocketRotation(FName("Proiettile"))
			);
		Bullet->Lancio(Aiming->VelLancio);
		Reload = ReloadTime;
	}

}

// Called every frame
void ATankC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Reload > 0) Reload -= DeltaTime;
}

// Called to bind functionality to input
void ATankC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

