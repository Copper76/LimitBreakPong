// Fill out your copyright notice in the Description page of Project Settings.


#include "PongPlayerController.h"
#include "Kismet/GameplayStatics.h" 

void APongPlayerController::BeginPlay()
{
	bAutoManageActiveCameraTarget = false;

	Super::BeginPlay();
}