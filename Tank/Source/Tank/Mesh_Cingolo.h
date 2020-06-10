// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Mesh_Cingolo.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_API UMesh_Cingolo : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	UMesh_Cingolo();


	UPROPERTY(EditAnyWhere, Category = "Controls")
		float ForzaMaxCingolo;

	UFUNCTION(BlueprintCallable, Category = "Controls")
		void RichiestaMovimento(float Movimento);

};
