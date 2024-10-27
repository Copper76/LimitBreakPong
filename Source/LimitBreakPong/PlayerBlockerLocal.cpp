// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBlockerLocal.h"
#include "EnhancedInputSubsystems.h"
#include "PongPlayerController.h"
#include "Kismet/GameplayStatics.h" 
#include "PongGameState.h"
#include "EnhancedInputComponent.h"

void APlayerBlockerLocal::BeginPlay()
{
	Super::BeginPlay();

	if (!Controller)
	{
		Controller = UGameplayStatics::CreatePlayer(GetWorld(), -1, true);
		Controller->Possess(this);
	}

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			subsystem->AddMappingContext(m_DefaultMappingContext, 0);
		}
	}

	Tags.Add("RIGHT");

	if (m_SecondPlayerTemplate)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.Owner = this;

		m_SecondPlayer = GetWorld()->SpawnActor<ABlocker>(m_SecondPlayerTemplate, m_SecondPlayerTransform, SpawnParams);

		m_SecondPlayer->Tags.Add("LEFT");
	}
}

// Called to bind functionality to input
void APlayerBlockerLocal::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		////Moving
		enhancedInputComponent->BindAction(m_MoveAction, ETriggerEvent::Triggered, this, &APlayerBlockerLocal::MovePlayerLeft);
		enhancedInputComponent->BindAction(m_MoveActionSecondary, ETriggerEvent::Triggered, this, &APlayerBlockerLocal::MovePlayerRight);
	}
}

void APlayerBlockerLocal::MovePlayerLeft(const FInputActionValue& Value)
{
	const float movement = Value.Get<float>();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Green, TEXT("Player 1 moving!"));
	}

	Move(movement);
}

void APlayerBlockerLocal::MovePlayerRight(const FInputActionValue& Value)
{
	const float movement = Value.Get<float>();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 5.0f, FColor::Green, TEXT("Player 2 moving!"));
	}

	m_SecondPlayer->Move(movement);
}
