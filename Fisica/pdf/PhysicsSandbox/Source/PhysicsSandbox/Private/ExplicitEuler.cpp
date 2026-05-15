#include "ExplicitEuler.h"

UExplicitEuler::UExplicitEuler()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UExplicitEuler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Owner = GetOwner();

	FTransform OwnerTransform = Owner->GetActorTransform();
	FVector OwnerLocation = OwnerTransform.GetLocation();

	FVector PivotLocation;

	if (Pivot != nullptr)
	{
		PivotLocation = Pivot->GetTransform().GetLocation();
	}
	else
	{
		PivotLocation = FVector::ZeroVector;
	}

	const FVector DistanceFromPivot = OwnerLocation - PivotLocation;

	const FVector Force = -K * DistanceFromPivot - Damp * Velocity;
	const FVector Acceleration = Force / FMath::Max(Mass, KINDA_SMALL_NUMBER);

	OwnerLocation += Velocity * DeltaTime;
	Velocity += Acceleration * DeltaTime;

	OwnerTransform.SetLocation(OwnerLocation);

	Owner->SetActorTransform(OwnerTransform);
}