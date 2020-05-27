// Fill out your copyright notice in the Description page of Project Settings.


#include "Aiming_Component.h"
#include "Kismet/GameplayStatics.h"
#include "MeshTorretta.h"
// Sets default values for this component's properties
UAiming_Component::UAiming_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	VelLancio = 100000.f;
	// ...
}


// Called when the game starts
void UAiming_Component::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAiming_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAiming_Component::AimAt(FVector HitLocation)
{

	if (!Cannone) return;
	FVector Velocity;
	FVector StartLocation = Cannone->GetSocketLocation(FName("Proiettile"));
		bool results = UGameplayStatics::SuggestProjectileVelocity
		(this, //L'oggetto che esegue
			Velocity,	//passata per riferimento direzione da calcolare
			StartLocation,	
			HitLocation,
			VelLancio,		//forza di lancio
			false,		//Arco alto si o no
			0,			//eventuale raggio di collisione
			0,			//sovrascivi gravità
			ESuggestProjVelocityTraceOption::DoNotTrace		//parametri del trace
		);

		if (results)
		{

			RuotaCannone(Velocity);
		}

	
		
	//UE_LOG(LogTemp, Warning, TEXT("il Tank %s Mira a %s"), *GetOwner()->GetName(), *HitLocation.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("pos Barrel %s"), *Cannone->GetComponentLocation().ToString());
}

void UAiming_Component::RuotaCannone(FVector &Velocity)
{
	FVector AimDirection = Velocity.GetSafeNormal();
	UE_LOG(LogTemp, Warning, TEXT("Angolazione %s"), *AimDirection.ToString());

	FRotator RotAttuale = Cannone->GetForwardVector().Rotation();
	FRotator RotObbiettivo = AimDirection.Rotation();
	FRotator DeltaRot = RotObbiettivo - RotAttuale;

	Cannone->Eleva(DeltaRot.Pitch);

	if (FMath::Abs(DeltaRot.Yaw) < 180)
	{
		Torre->Ruota(DeltaRot.Yaw);
	}
	

	else

	{

		Torre->Ruota(-DeltaRot.Yaw);
	}

}

void UAiming_Component::SetCannone(UMeshTorretta* Cannon)
{
	Cannone = Cannon;
}

void UAiming_Component::SetTorre(UMeshTorretta * Turret)
{
	Torre = Turret;

}

