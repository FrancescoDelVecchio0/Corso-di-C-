#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CustomRigidBodyController.generated.h"

UCLASS()
class PHYSICSSANDBOX_API ACustomRigidBodyController : public APawn
{
	GENERATED_BODY()

public:

	ACustomRigidBodyController();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:

	void ApplyForce();
};
