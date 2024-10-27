// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Net/UnrealNetwork.h"

void APongGameState::BeginPlay()
{
    Super::BeginPlay();

    TArray<AActor*> FoundActors;
    AActor* Camera = nullptr;

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), FoundActors);

    if (FoundActors.Num() > 0)
    {
         Camera = FoundActors[0];
    }

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerController::StaticClass(), FoundActors);

    for (AActor* Actor : FoundActors)
    {
        APlayerController* PC = Cast<APlayerController>(Actor);
        if (PC)
        {
            PC->SetViewTarget(Camera);
        }
    }
}

void APongGameState::ScoreLeft()
{
    m_LeftPlayerScore++;
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PLAYER 1 SCORE!"));
    UpdateScore();
}

void APongGameState::ScoreRight()
{
    m_RightPlayerScore++;
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PLAYER 2 SCORE!"));
    UpdateScore();
}

void APongGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(APongGameState, m_LeftPlayerScore);
    DOREPLIFETIME(APongGameState, m_RightPlayerScore);
}
