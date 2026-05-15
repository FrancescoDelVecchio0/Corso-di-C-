#include "ImplicitEulerAsync.h"

UImplicitEulerAsync::UImplicitEulerAsync()
{
	bAutoActivate = true;

	PrimaryComponentTick.bCanEverTick = true;
}

void UImplicitEulerAsync::Activate(bool bReset)
{
	Super::Activate(bReset);
}

void UImplicitEulerAsync::Deactivate()
{
	Super::Deactivate();
}

void UImplicitEulerAsync::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UImplicitEulerAsync::AsyncPhysicsTickComponent(float DeltaTime, float SimTime)
{
	Super::AsyncPhysicsTickComponent(DeltaTime, SimTime);
}