#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ImplicitEuler.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHYSICSSANDBOX_API UImplicitEuler : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, Category = "Implicit Euler")
	AActor*		Pivot = nullptr;
	UPROPERTY(EditAnywhere, Category = "Implicit Euler", meta = (Units = "kg", ClampMin = "0.0", UIClampMin = "0.0"))
	float		Mass = 1.f;
	UPROPERTY(EditAnywhere, Category = "Implicit Euler", meta = (ClampMin = "0.0", UIClampMin = "0.0"))
	float		K = 15.f;
	UPROPERTY(EditAnywhere, Category = "Implicit Euler", meta = (ClampMin = "0.0", UIClampMin = "0.0"))
	float		Damp = 0.1f;

	UPROPERTY(VisibleInstanceOnly, Transient, Category = "Implicit Euler")
	FVector		Velocity = FVector::ZeroVector;

public:

	UImplicitEuler();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};