#include "CppBaseActor.h"

ACppBaseActor::ACppBaseActor()
{
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	SetRootComponent(mesh);
}


void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();

	initialLocation = GetActorLocation();
}

void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float ACppBaseActor::SinMovement(float timeSeconds) {

	double sinMovement;
	double cosMovement;

	FMath::SinCos(&sinMovement, &cosMovement, StaticCast<double>(timeSeconds * frequency));

	return  amplitude * StaticCast<float>(sinMovement);
}