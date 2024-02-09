// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	RootComponent = ProjectileMesh; 

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component")); 
	ProjectileMovementComponent->InitialSpeed = 1300.f; 
	ProjectileMovementComponent->MaxSpeed = 1300.f; 

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnHit(
	UPrimitiveComponent* HitComp, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	FVector NormalImpulse, 
	const FHitResult& Hit
	)
{
	/*
	UE_LOG(LogTemp, Warning, TEXT("OnHit"));
	UE_LOG(LogTemp, Warning, TEXt("HitComp: %s"), *HitComp->GetName()); 
	UE_LOG(LogTemp, Warning, TEXt("OtherActor: %s"), *OtherActor->GetName()); 
	UE_LOG(LogTemp, Warning, TEXt("OtherComp: %s"), *OtherComp->GetName()); 
	*/

	auto MyOwner = GetOwner(); 

	if (MyOwner == nullptr) return; 

	auto MyOwnInstigator = MyOwner->GetInstiagtorController(); 
	auto DamageTypeClass = UDamageType::StaticClass(); 

	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwnInstigator, this, DamageTypeClass); 
		Destroy(); 
	}

}

