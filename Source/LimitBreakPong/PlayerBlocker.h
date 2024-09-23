// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blocker.h"
#include "PlayerBlocker.generated.h"

/**
 * 
 */
UCLASS()
class LIMITBREAKPONG_API APlayerBlocker final : public ABlocker
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* m_DefaultMappingContext;
};
