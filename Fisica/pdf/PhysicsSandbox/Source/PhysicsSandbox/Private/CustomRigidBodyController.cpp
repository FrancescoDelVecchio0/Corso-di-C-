#include "CustomRigidBodyController.h"
#include "CustomRigidbody.h"

#include "Components/InputComponent.h"

ACustomRigidBodyController::ACustomRigidBodyController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACustomRigidBodyController::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);

	InInputComponent->BindAction("ApplyForce", IE_Pressed, this, &ACustomRigidBodyController::ApplyForce);
}

void ACustomRigidBodyController::ApplyForce()
{
	ApplyForceToNativeRigidbody();
	ApplyForceToCustomRigidbody();
}

void ACustomRigidBodyController::ApplyForceToNativeRigidbody()
{
    if (NativeRigidbody == nullptr)
    {
        return;
    }

    USceneComponent* SceneComponent = NativeRigidbody->GetRootComponent();

    if (SceneComponent == nullptr)
    {
        return;
    }

    UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(SceneComponent);

    if (PrimitiveComponent == nullptr)
    {
        return;
    }

    const FTransform WorldTransform = PrimitiveComponent->GetComponentTransform();
    const FVector WorldSpaceApplicationPoint = WorldTransform.TransformPosition(BodySpaceApplicationPoint);

    PrimitiveComponent->AddForceAtLocation(ForceToApply, WorldSpaceApplicationPoint);
}

void ACustomRigidBodyController::ApplyForceToCustomRigidbody()
{
    if (CustomRigidbody == nullptr)
    {
        return;
    }

    UCustomRigidbody* CustomRigidBodyComponent = CustomRigidbody->GetComponentByClass<UCustomRigidbody>();

    if (CustomRigidBodyComponent == nullptr)
    {
        return;
    }

    const FTransform WorldTransform = CustomRigidbody->GetActorTransform();
    const FVector WorldSpaceApplicationPoint = WorldTransform.TransformPosition(BodySpaceApplicationPoint);

    CustomRigidBodyComponent->AddForceAtLocation(ForceToApply, WorldSpaceApplicationPoint);
}