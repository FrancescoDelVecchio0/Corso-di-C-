#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ImplicitEulerAsync.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHYSICSSANDBOX_API UImplicitEulerAsync : public UActorComponent
{
	GENERATED_BODY()

public:

	UImplicitEulerAsync();

	virtual void Activate(bool bReset = false) override;
	virtual void Deactivate() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void AsyncPhysicsTickComponent(float DeltaTime, float SimTime) override;
};