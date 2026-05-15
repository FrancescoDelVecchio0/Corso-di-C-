#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PhysicsSandboxPawn.generated.h"

UCLASS()
class PHYSICSSANDBOX_API APhysicsSandboxPawn : public APawn
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, Category = "Target")
	AActor*		PhysicsActor = nullptr;

	UPROPERTY(EditAnywhere, Category = "Force")
	FVector		ForceToApply = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Force")
	FVector		BodySpaceApplicationPoint = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Torque")
	FVector		TorqueToApply = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Debug Draw")
	bool		bEnableDebugDraw = false;
	UPROPERTY(EditAnywhere, Category = "Debug Draw")
	float		ForceDrawScale = 1.f;
	UPROPERTY(EditAnywhere, Category = "Debug Draw")
	float		VelocityDrawScale = 1.f;
	UPROPERTY(EditAnywhere, Category = "Debug Draw")
	float		AngularVelocityDrawScale = 1.f;

public:	

	APhysicsSandboxPawn();

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

private:

	void ApplyForce();
};