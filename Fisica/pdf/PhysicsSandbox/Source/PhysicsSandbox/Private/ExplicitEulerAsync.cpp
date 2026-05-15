#include "ExplicitEulerAsync.h"

UExplicitEulerAsync::UExplicitEulerAsync()
{
	bAutoActivate = true;

	PrimaryComponentTick.bCanEverTick = true;
}

void UExplicitEulerAsync::Activate(bool bReset)
{
	Super::Activate(bReset);
}

void UExplicitEulerAsync::Deactivate()
{
	Super::Deactivate();
}

void UExplicitEulerAsync::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UExplicitEulerAsync::AsyncPhysicsTickComponent(float DeltaTime, float SimTime)
{
	Super::AsyncPhysicsTickComponent(DeltaTime, SimTime);
}