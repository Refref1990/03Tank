// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank_AIC.generated.h"

/**
 * 
 */
UCLASS()
class TANK_API ATank_AIC : public AAIController
{
	GENERATED_BODY()

		float Timer;


public:

	ATank_AIC();

	class ATankC* GetTank() const;

	class ATankC* GetPlayerTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
};
