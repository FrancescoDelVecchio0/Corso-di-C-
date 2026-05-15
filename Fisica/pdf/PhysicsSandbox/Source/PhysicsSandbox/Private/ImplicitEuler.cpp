#include "ImplicitEuler.h"

UImplicitEuler::UImplicitEuler()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UImplicitEuler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
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

	Velocity += Acceleration * DeltaTime;
	OwnerLocation += Velocity * DeltaTime;

	OwnerTransform.SetLocation(OwnerLocation);

	Owner->SetActorTransform(OwnerTransform);
}