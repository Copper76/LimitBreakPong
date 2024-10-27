// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PongPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LIMITBREAKPONG_API APongPlayerController final : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
};
