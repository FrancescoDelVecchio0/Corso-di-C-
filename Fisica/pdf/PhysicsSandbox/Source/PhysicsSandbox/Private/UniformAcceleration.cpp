#include "UniformAcceleration.h"

UUniformAcceleration::UUniformAcceleration()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UUniformAcceleration::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	FTransform OwnerTransform = Owner->GetActorTransform();
	FVector OwnerLocation = OwnerTransform.GetLocation();

	// s = s0 + v0 * t + 0.5 * a * t^2

	const FVector A = Force * 100.f / FMath::Max(Mass, KINDA_SMALL_NUMBER);
	const FVector S = 0.5f * A * Time * Time;

	OwnerLocation += S;

	OwnerTransform.SetLocation(OwnerLocation);

	Owner->SetActorTransform(OwnerTransform);
}

void UUniformAcceleration::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// TODO: Fill me!
}  
