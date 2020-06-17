// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshTorretta.h"

UMeshTorretta::UMeshTorretta()
{
	RotMaxSec = 20.f;

	RotMaxSec = 30.f;

	ElevazioneMax = 90.f;

	ElevazioneMin = 0.f;

}

void UMeshTorretta::Eleva(float velrelativita)
{

	//UE_LOG(LogTemp, Warning, TEXT("rotazione verso %f"), velrelativita);
	velrelativita = FMath::Clamp<float>(velrelativita, -1, 1);
	
	float CambioLevatura = velrelativita * RotMaxSec * GetWorld()->DeltaTimeSeconds;

	float NuovaLevatura = RelativeRotation.Pitch + CambioLevatura;

	NuovaLevatura = FMath::Clamp<float>(NuovaLevatura, ElevazioneMin, ElevazioneMax);

	SetRelativeRotation(FRotator(NuovaLevatura, 0, 0));
}



void UMeshTorretta::Ruota(float velrelativita)
{

	//UE_LOG(LogTemp, Warning, TEXT("rotazione verso %f"), velrelativita);
	velrelativita = FMath::Clamp<float>(velrelativita, -1, 1);

	float CambioRotazione = velrelativita * RotHMaxSec * GetWorld()->DeltaTimeSeconds;

	float NuovaRotazione = RelativeRotation.Yaw + CambioRotazione;



	SetRelativeRotation(FRotator(0, NuovaRotazione, 0));
}

