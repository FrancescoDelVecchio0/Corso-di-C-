#include "PhysicsSandboxPawn.h"

#include "Components/InputComponent.h"

#include "DrawDebugHelpers.h"

APhysicsSandboxPawn::APhysicsSandboxPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APhysicsSandboxPawn::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);

	InInputComponent->BindAction("ApplyForce", IE_Pressed, this, &APhysicsSandboxPawn::ApplyForce);
}

void APhysicsSandboxPawn::ApplyForce()
{
    // TODO: Fill me!
}

void APhysicsSandboxPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

#if ENABLE_DRAW_DEBUG

    if (PhysicsActor == nullptr)
    {
        return;
    }

    USceneComponent* SceneComponent = PhysicsActor->GetRootComponent();

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

    const FVector CoM = WorldTransform.GetLocation();

    DrawDebugPoint(GetWorld(), WorldSpaceApplicationPoint, 10.f, FColor::Red, false, -1.f, SDPG_Foreground);

    const FVector Arm = WorldSpaceApplicationPoint - CoM;

    if (!Arm.IsNearlyZero())
    {
        DrawDebugDirectionalArrow(GetWorld(), CoM, WorldSpaceApplicationPoint, 10.f, FColor::Red, false, -1.f, SDPG_Foreground);
    }

    DrawDebugDirectionalArrow(GetWorld(), WorldSpaceApplicationPoint, WorldSpaceApplicationPoint + ForceToApply * ForceDrawScale, 10.f, FColor::Red, false, -1.f, SDPG_Foreground);

    const FVector LinearVelocity = PrimitiveComponent->GetPhysicsLinearVelocity();
    const FVector AngularVelocity = PrimitiveComponent->GetPhysicsAngularVelocityInRadians();

    DrawDebugDirectionalArrow(GetWorld(), WorldSpaceApplicationPoint, WorldSpaceApplicationPoint + LinearVelocity * VelocityDrawScale, 10.f, FColor::Green, false, -1.f, SDPG_Foreground);
    DrawDebugDirectionalArrow(GetWorld(), WorldSpaceApplicationPoint, WorldSpaceApplicationPoint + AngularVelocity * AngularVelocityDrawScale, 10.f, FColor::Blue, false, -1.f, SDPG_Foreground);

#endif // ENABLE_DRAW_DEBUG
}