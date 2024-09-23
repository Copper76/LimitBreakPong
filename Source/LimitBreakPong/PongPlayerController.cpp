// Fill out your copyright notice in the Description page of Project Settings.


#include "PongPlayerController.h"
#include "Kismet/GameplayStatics.h" 

void APongPlayerController::BeginPlay()
{
	Super::BeginPlay();

	APlayerCameraManager* sharedCameraManager = Cast<APlayerCameraManager>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCameraManager::StaticClass()));

	if (sharedCameraManager)
	{
		PlayerCameraManager = sharedCameraManager;
		// Set the view target to the overview camera
		SetViewTarget(sharedCameraManager);
	}
}
