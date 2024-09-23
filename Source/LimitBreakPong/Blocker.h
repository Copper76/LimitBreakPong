// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Blocker.generated.h"

struct FInputActionValue;

UCLASS()
class LIMITBREAKPONG_API ABlocker : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABlocker();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void Move(const FInputActionValue& Value);

private:
	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* m_MoveAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_Mesh;

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Defaults, meta = (AllowPrivateAccess = "true"))
	float m_MaxY;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Defaults, meta = (AllowPrivateAccess = "true"))
	float m_MinY;
};