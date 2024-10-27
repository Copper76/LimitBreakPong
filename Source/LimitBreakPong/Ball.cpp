// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "PongGameState.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	m_Mesh->SetEnableGravity(false);
	m_Mesh->CastShadow = false;
	m_Mesh->SetSimulatePhysics(false);
	SetRootComponent(m_Mesh);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	m_Mesh->OnComponentBeginOverlap.AddDynamic(this, &ABall::OnOverlap);
}

void ABall::OnOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor->ActorHasTag(TEXT("Horizontal")))
	{
		m_TravelDir.Y *= -1.0f;
	}

	if (otherActor->ActorHasTag(TEXT("LEFT")))
	{
		m_TravelDir.X = 1.0f;
		m_SpeedModifier = FMath::Min(1.5f, m_SpeedModifier + 0.1f);
	}

	if (otherActor->ActorHasTag(TEXT("RIGHT")))
	{
		m_TravelDir.X = -1.0f;
		m_SpeedModifier = FMath::Min(1.5f, m_SpeedModifier + 0.1f);
	}

	if (otherActor->ActorHasTag(TEXT("LEFTWIN")))
	{
		ScoreLeft();
	}

	if (otherActor->ActorHasTag(TEXT("RIGHTWIN")))
	{
		ScoreRight();
	}
}

void ABall::ScoreLeft()
{
	APongGameState* GameState = GetWorld()->GetGameState<APongGameState>();
	if (GameState)
	{
		GameState->ScoreLeft();
	}
	m_TravelDir.X = 1.0f;

	ResetBall();
}

void ABall::ScoreRight()
{
	APongGameState* GameState = GetWorld()->GetGameState<APongGameState>();
	if (GameState)
	{
		GameState->ScoreRight();
	}
	m_TravelDir.X = -1.0f;

	ResetBall();
}

void ABall::ResetBall()
{
	SetActorTickEnabled(false);
	m_Mesh->SetWorldLocation(FVector::ZeroVector, false, nullptr, ETeleportType::TeleportPhysics);
	m_SpeedModifier = 1.0f;

	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, this, &ABall::StartBall, m_ResetTime, false);
}

void ABall::StartBall()
{
	SetActorTickEnabled(true);
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_Mesh->AddRelativeLocation(m_TravelDir * m_TravelSpeed * m_SpeedModifier, true, nullptr, ETeleportType::TeleportPhysics);
}

