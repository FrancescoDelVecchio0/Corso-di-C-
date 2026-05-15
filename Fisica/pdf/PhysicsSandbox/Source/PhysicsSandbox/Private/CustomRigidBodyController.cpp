#include "CustomRigidBodyController.h"

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
    // TODO: Fill me!
}