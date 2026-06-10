#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CustomRigidBodyController.generated.h"

UCLASS()
class PHYSICSSANDBOX_API ACustomRigidBodyController : public APawn
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, Category = "Target")
	AActor*		NativeRigidbody = nullptr;
	UPROPERTY(EditAnywhere, Category = "Target")
	AActor*		CustomRigidbody = nullptr;

	UPROPERTY(EditAnywhere, Category = "Force")
	FVector		ForceToApply = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Force")
	FVector		BodySpaceApplicationPoint = FVector::ZeroVector;

public:

	ACustomRigidBodyController();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:

	void ApplyForce();

	void ApplyForceToNativeRigidbody();
	void ApplyForceToCustomRigidbody();
};
