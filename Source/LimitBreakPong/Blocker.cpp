// Fill out your copyright notice in the Description page of Project Settings.


#include "Blocker.h"

// Sets default values
ABlocker::ABlocker()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Blocker"));
	m_Mesh->SetEnableGravity(false);
	m_Mesh->CastShadow = false;
	SetRootComponent(m_Mesh);
}

// Called when the game starts or when spawned
void ABlocker::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABlocker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABlocker::Move(const float Value)
{
	const FVector oldLocation = GetActorLocation();

	SetActorLocation(FVector(oldLocation.X, FMath::Clamp(oldLocation.Y + Value, m_MinY, m_MaxY), oldLocation.Z));
}

