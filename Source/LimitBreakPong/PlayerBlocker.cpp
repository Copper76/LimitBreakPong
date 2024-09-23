// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBlocker.h"
#include "EnhancedInputSubsystems.h"
#include "PongPlayerController.h"
#include "Kismet/GameplayStatics.h" 

void APlayerBlocker::BeginPlay()
{
	Super::BeginPlay();

	if (!Controller)
	{
		Controller = UGameplayStatics::CreatePlayer(GetWorld(), -1, true);
		Controller->Possess(this);
		Cast<APongPlayerController>(Controller)->bAutoManageActiveCameraTarget = false;
	}

	if (APlayerController* playerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			subsystem->AddMappingContext(m_DefaultMappingContext, 0);
		}
	}
}
