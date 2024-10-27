// Fill out your copyright notice in the Description page of Project Settings.


#include "PVPGameMode.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void APVPGameMode::BeginPlay()
{
    Super::BeginPlay();

    GetGameInstance()->GetGameViewportClient()->SetDisableSplitscreenOverride(true);
}
