#include "NumericalIntergration.h"

#include "DrawDebugHelpers.h"

UNumericalIntergration::UNumericalIntergration()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UNumericalIntergration::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	FTransform OwnerTransform = Owner->GetActorTransform();
	FVector OwnerLocation = OwnerTransform.GetLocation();

	FVector Position = OwnerLocation;
	FVector Velocity = FVector::ZeroVector;

	float T = 0.f;

	if (TimeStep > 0.f)
	{
		const FVector Acceleration = Force * 100.f / FMath::Max(Mass, KINDA_SMALL_NUMBER);

		while (T < Time)
		{
			Position = Position + Velocity * TimeStep;
			Velocity = Velocity + Acceleration * TimeStep;

			T += TimeStep;
		}
	}

	OwnerTransform.SetLocation(Position);

	Owner->SetActorTransform(OwnerTransform);
}

void UNumericalIntergration::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    // TODO: Fill me!
}  