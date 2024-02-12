// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

ATank::ATank()
{

    SpringArm = CreatDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm")); 
    SpringArm->SetupAttachment(RootComponent); 

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm); 


}

void ATank::BeginPlay()
{
    Super::BeginPlay(); 
    TankPlayerController = Cast<APlayerController>(GetController());

}

void ATank::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime); 
    if (TankPlayerController)
    {
        FHitResult HitResult; 
        TankPlayerController->GetHitResultUndertheCursor(
                                ECollisionChannel::ECC_Visibility, 
                                false, 
                                HitResult);

        DrawDebugSphere
            (
                GetWorld(), // const UWorld*
                HitResult.ImpactPoint, // FVector Const& Center 
                25.f, // sphere radius
                12, // sphere segments
                FColor::Red, // sphere color
                false, // whether to persistent the line 
                -1.f // if not persistent, set -1 
            );

        RotateTurret(HitResult.ImpactPoint); 

    }
    
}

void ATower::HandleDestruction()
{
    Super::HandleDestruction(); 
    SetActorHiddenInGame(true); 
    SetActorTickEnabled(false); 
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent); 

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
    
    PlayerInputComponent->BindMapping(TEXT("Fire"), IE_Pressed, this, &ATank::Fire); 
}

void ATank::Move(float Value)
{
    FVector DeltaLocation = FVector::ZeroVector;
    // X = DeltaTime * Value * Speed; 
    DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this); 
    AddActorLocalOffset(DeltaLocation, true); 
}

void ATank::Turn(float Value)
{
    FRotator DeltaRotation = FVector::ZeroRotator; 
    // X = DeltaTime * TurnRate * Value; 
    DeltaRotation.Yaw = TurnRate * Value * UGamePlayStatics::GetWorldDeltaSeconds(this); 
    AddActorLocalRotation(DeltaRotation); 

}

