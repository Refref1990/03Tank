// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "Movement.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_API UMovement : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	//UMovement();


	class UMesh_Cingolo* CingoloDX;

	class UMesh_Cingolo* CingoloSX;

	UFUNCTION(BlueprintCallable, Category = "Controlli")
	void MovimentoAvanti(float movimentoA);

	UFUNCTION(BlueprintCallable, Category = "Controlli")
	void MovimentoLaterale(float movimentoA);
	
	UFUNCTION(BlueprintCallable, Category = "Controlli")
		void SetCingoli(UMesh_Cingolo*RiferimentoDX, UMesh_Cingolo* RiferimentoSX);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;


};
