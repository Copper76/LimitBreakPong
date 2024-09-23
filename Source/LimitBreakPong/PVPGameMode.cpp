// Fill out your copyright notice in the Description page of Project Settings.


#include "PVPGameMode.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void APVPGameMode::BeginPlay()
{
    Super::BeginPlay();

    ACameraActor* sharedCamera = Cast<ACameraActor>(UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass()));
    APlayerCameraManager* cameraManager = Cast<APlayerCameraManager>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCameraManager::StaticClass()));

    cameraManager->SetActorLocation(sharedCamera->GetActorLocation());
    cameraManager->SetActorRotation(sharedCamera->GetActorRotation());
}
