// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank_PC.generated.h"

/**
 * 
 */
UCLASS()
class TANK_API ATank_PC : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnyWhere)
		float LineTraceRange;
	UPROPERTY(EditAnyWhere)
		float crossX;
	UPROPERTY(EditAnyWhere)
		float crossY;

public:
	ATank_PC();

	class ATankC* GetTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Mira();
	bool TrovaVista(FVector& Location);
	bool TrovaDirezione(FVector2D ScreenLocation, FVector& Direzione);
	bool TrovaHit(FVector Direzione, FVector& HitLocation);

};
