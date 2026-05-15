#include "CustomRigidbody.h"

UCustomRigidbody::UCustomRigidbody()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCustomRigidbody::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // TODO: Fill me!
}

void UCustomRigidbody::AddForceAtLocation(const FVector& InForce, const FVector& InAppPoint)
{
    // TODO: Fill me!
}

FMatrix CalculateInertiaTensorMatrix(const FQuat& InRotation, const FVector& InInertiaTensor, const FQuat& InInertiaTensorRotation)
{
    const FMatrix R = FRotationMatrix::Make(InInertiaTensorRotation);
    const FMatrix S = FScaleMatrix::Make(InInertiaTensor);

    const FMatrix InertiaTensorLocal = R * S * R.GetTransposed();

    const FMatrix RotationMatrix = FRotationMatrix::Make(InRotation);
    const FMatrix InertiaTensorWorld = RotationMatrix * InertiaTensorLocal * RotationMatrix.GetTransposed();

    return InertiaTensorWorld;
}

void UCustomRigidbody::Integrate(float InDeltaTime)
{
    // TODO: Fill me!
}
