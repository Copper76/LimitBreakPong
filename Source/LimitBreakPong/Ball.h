// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class LIMITBREAKPONG_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void StartBall();

private:
	void ResetBall();

	void ScoreLeft();

	void ScoreRight();

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Parameter, meta = (AllowPrivateAccess = "true"))
	float m_TravelSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Parameter, meta = (AllowPrivateAccess = "true"))
	float m_ResetTime;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Parameter, meta = (AllowPrivateAccess = "true"))
	FVector m_TravelDir = FVector(1.0f, 1.0f, 0.0f);

private:
	float m_SpeedModifier = 1.0f;
};
