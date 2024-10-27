// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PongGameState.generated.h"

/**
 * 
 */
UCLASS()
class LIMITBREAKPONG_API APongGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

public:
	void ScoreLeft();

	void ScoreRight();

public:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateScore();

private:
	UPROPERTY(Replicated, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 m_LeftPlayerScore = 0;

	UPROPERTY(Replicated, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 m_RightPlayerScore = 0;
};
