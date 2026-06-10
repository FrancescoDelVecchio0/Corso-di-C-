#include "CustomRigidbody.h"

UCustomRigidbody::UCustomRigidbody()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCustomRigidbody::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor* Owner = GetOwner();

    const FTransform OwnerTransform = Owner->GetActorTransform();

    Position = OwnerTransform.GetLocation();
    Rotation = OwnerTransform.GetRotation();

    Integrate(DeltaTime);

    const FTransform NewTransform = FTransform(Rotation, Position);

    Owner->SetActorTransform(NewTransform);
}

void UCustomRigidbody::AddForceAtLocation(const FVector& InForce, const FVector& InAppPoint)
{
    ForceToApply += InForce;

    const FVector Arm = InAppPoint - Position;
    const FVector Torque = FVector::CrossProduct(Arm, InForce);

    TorqueToApply += Torque;
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
    LinearAcceleration = ForceToApply / FMath::Max(KINDA_SMALL_NUMBER, Mass);

    const FMatrix InertiaTensorMatrix = CalculateInertiaTensorMatrix(Rotation, InertiaTensor * Mass * 10000.f, FQuat::Identity);
    AngularAcceleration = InertiaTensorMatrix.InverseTransformVector(TorqueToApply);

    // Integrate velocities.

    LinearVelocity += LinearAcceleration * InDeltaTime;
    AngularVelocity += AngularAcceleration * InDeltaTime;

    // Integrate position and rotation.

    Position += LinearVelocity * InDeltaTime;

    const FQuat DeltaRot = FQuat(AngularVelocity.X, AngularVelocity.Y, AngularVelocity.Z, 0.f) * Rotation * 0.5f * InDeltaTime;
    Rotation += DeltaRot;

    ForceToApply = FVector::ZeroVector;
    TorqueToApply = FVector::ZeroVector;
}
