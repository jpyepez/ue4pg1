// Fill out your copyright notice in the Description page of Project Settings.

#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FVector NewLocation = GetActorLocation();
    float DeltaLatitude = (FMath::Sin(RunningTimeX + DeltaTime) - FMath::Sin(RunningTimeX));
    float DeltaLongitude = (FMath::Sin(RunningTimeY + DeltaTime) - FMath::Sin(RunningTimeY));
    float DeltaNormal = (FMath::Sin(RunningTimeZ + DeltaTime) - FMath::Sin(RunningTimeZ));
    NewLocation.X += DeltaLongitude * XOscAmplitude;  // Scale longitude position by a factor of XOscAmplitude
    NewLocation.Y += DeltaLatitude * YOscAmplitude;   // Scale latitude position by a factor of YOscAmplitude
    NewLocation.Z += DeltaNormal * ZOscAmplitude;     //Scale our height by a factor of ZOscAmplitude
    RunningTimeX += DeltaTime * 0.6;
    RunningTimeY += DeltaTime * 1.2;
    RunningTimeZ += DeltaTime;
    SetActorLocation(NewLocation);
}

