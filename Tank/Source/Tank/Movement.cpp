// Fill out your copyright notice in the Description page of Project Settings.


#include "Movement.h"
#include "Mesh_Cingolo.h"

void UMovement::MovimentoAvanti(float movimentoA)
{
	//UE_LOG(LogTemp, Warning, TEXT("Avanti %f"), movimentoA);
	if (!CingoloDX || !CingoloSX) return;
	CingoloDX->RichiestaMovimento(movimentoA);
	CingoloSX->RichiestaMovimento(movimentoA);
}

void UMovement::MovimentoLaterale(float movimentoA)
{

	//UE_LOG(LogTemp, Warning, TEXT("Laterale %f"), movimentoA);
	if (!CingoloDX || !CingoloSX) return;
	CingoloDX->RichiestaMovimento(movimentoA);
	CingoloSX->RichiestaMovimento(-movimentoA);
}

void UMovement::SetCingoli(UMesh_Cingolo*RiferimentoDX, UMesh_Cingolo* RiferimentoSX)
{
	CingoloDX = RiferimentoDX;
	CingoloSX = RiferimentoSX;
}

void UMovement::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s Velocity %s"),*GetOwner()->GetName(),*MoveVelocity.GetSafeNormal().ToString());
	FVector IntAvanti = MoveVelocity.GetSafeNormal();
	FVector TankAvanti = GetOwner()->GetActorForwardVector().GetSafeNormal();
	float prodottoscalare = FVector::DotProduct(IntAvanti, TankAvanti);
	MovimentoAvanti(prodottoscalare);

	float prodottovettoriale = FVector::CrossProduct(IntAvanti, TankAvanti).Z;
	MovimentoLaterale(prodottovettoriale);
}
