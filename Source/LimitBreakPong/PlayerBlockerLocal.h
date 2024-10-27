// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blocker.h"
#include "PlayerBlockerLocal.generated.h"

UCLASS()
class LIMITBREAKPONG_API APlayerBlockerLocal final : public ABlocker
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MovePlayerLeft(const FInputActionValue& Value);

	void MovePlayerRight(const FInputActionValue& Value);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* m_MoveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* m_MoveActionSecondary;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* m_DefaultMappingContext;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = SecondPlayer, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ABlocker> m_SecondPlayerTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SecondPlayer, meta = (AllowPrivateAccess = "true"))
	FTransform m_SecondPlayerTransform;

	ABlocker* m_SecondPlayer;
};
