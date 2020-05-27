// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MeshTorretta.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_API UMeshTorretta : public UStaticMeshComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnyWhere, Category = "Setup")
	float RotMaxSec;

	UPROPERTY(EditAnyWhere, Category = "Setup")
	float ElevazioneMax;

	UPROPERTY(EditAnyWhere, Category = "Setup")
	float ElevazioneMin;

	UPROPERTY(EditAnyWhere, Category = "Setup")
		float RotHMaxSec;
	
public:

	UMeshTorretta();

	void Eleva(float velrelativita);
	void Ruota(float velrelativita);


};
