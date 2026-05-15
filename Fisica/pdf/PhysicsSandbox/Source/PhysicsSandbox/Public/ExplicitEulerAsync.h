#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ExplicitEulerAsync.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHYSICSSANDBOX_API UExplicitEulerAsync : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, Category = "Explicit Euler")
	AActor*		Pivot = nullptr;
	UPROPERTY(EditAnywhere, Category = "Explicit Euler")
	float		Mass = 1.f;
	UPROPERTY(EditAnywhere, Category = "Explicit Euler")
	float		K = 15.f;
	UPROPERTY(EditAnywhere, Category = "Explicit Euler")
	float		Damp = 0.1f;

	UPROPERTY(VisibleAnywhere, Transient, Category = "Explicit Euler")
	FTransform	Transform = FTransform::Identity;
	UPROPERTY(VisibleAnywhere, Transient, Category = "Explicit Euler")
	FVector		Velocity = FVector::ZeroVector;

public:

	UExplicitEulerAsync();

	virtual void Activate(bool bReset = false) override;
	virtual void Deactivate() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void AsyncPhysicsTickComponent(float DeltaTime, float SimTime) override;
};