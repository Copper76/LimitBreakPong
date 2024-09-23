// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	m_Mesh->SetEnableGravity(false);
	m_Mesh->CastShadow = false;
	SetRootComponent(m_Mesh);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	m_Mesh->OnComponentHit.AddDynamic(this, &ABall::OnHit);

	m_Mesh->OnComponentBeginOverlap.AddDynamic(this, &ABall::OnOverlap);
}

void ABall::OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hit)
{
	if (otherActor->ActorHasTag(TEXT("Horizontal")))
	{
		m_TravelDir.Y *= -1.0f;
	}

	if (otherActor->ActorHasTag(TEXT("Vertical")))
	{
		m_TravelDir.X *= -1.0f;
	}
}

void ABall::OnOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("SCORE!"));
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + m_TravelDir * m_TravelSpeed);
}

