// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatistics.h"

ATank::ATank()
{

    SpringArm = CreatDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm")); 
    SpringArm->SetupAttachment(RootComponent); 

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm); 


}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent); 
    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

void ATank::Move(float Value)
{
    FVector DeltaLocation = FVector::ZeroVector;
    // X = DeltaTime * Value * Speed; 
    DeltaLocation.X = Value * Speed * UGameplayStatistics::GetWorldDeltaSeconds(this); 
    AddActorLocalOffset(DeltaLocation, true); 
}

void ATank::Turn(float Value)
{
    FRotator DeltaRotation = FVector::ZeroRotator; 
    // X = DeltaTime * TurnRate * Value; 
    DeltaRotation.Yaw = TurnRate * Value * UGamePlayStatistics::GetWorldDeltaSeconds(this); 
    AddActorLocalRotation(DeltaRotation); 

}

