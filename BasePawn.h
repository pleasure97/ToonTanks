// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	/*
	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyInt = 5; 

	UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleDefaultsOnlyInt = 6; 

	UPROPERTY(EditDefaultsOnly)
	int32 EditDefaultsOnlyInt = 7; 

	UPROPERTY(EditInstanceOnly)
	int32 EditInstanceOnlyInt = 8; 

	UPROPERTY(EditAnywhere)
	float Speed = 50.f; 
	*/

	void HandleDestruction(); 

protected:
	void RotateTurret(FVector LookAtTarget); 

	void Fire(); 

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* BaseMesh;  

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* TurretMesh; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	USceneComponent* ProjectileSpawnPoint; 

	UPROPERTY(EditAnywhere, Category="Combat")
	class UParticleSystem* DeathParticles; 

	UPROPERTY(EditAnywhere, Category="Combat")
	class USoundBase* DeathSound; 

	UPROPERTY(EditAnywhere, Category="Combat")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass; 

	/*
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Super Duper Variables", meta = (AllowPrivateAccess = "true"))
	int32 VisibleAnywhereInt = 12; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Super Duper Variables", meta = (AllowPrivateAccess = "true"))
	int32 EditAnywhereInt = 22; 
	*/
};
