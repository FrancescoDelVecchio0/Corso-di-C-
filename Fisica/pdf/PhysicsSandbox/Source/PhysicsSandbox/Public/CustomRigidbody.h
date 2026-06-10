#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomRigidbody.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHYSICSSANDBOX_API UCustomRigidbody : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, Category = "Rigidbody", meta = (Units = "kg"))
	float	Mass = 1.f;
	UPROPERTY(EditAnywhere, Category = "Rigidbody")
	FVector InertiaTensor = FVector::OneVector;

	UPROPERTY(VisibleInstanceOnly, Transient, Category = "Dynamics")
	FVector Position = FVector::ZeroVector;
	UPROPERTY(VisibleInstanceOnly, Transient, Category = "Dynamics")
	FQuat Rotation = FQuat::Identity;

	UPROPERTY(VisibleInstanceOnly, Transient, Category = "Dynamics")
	FVector LinearVelocity = FVector::ZeroVector;
	UPROPERTY(VisibleInstanceOnly, Transient, Category = "Dynamics")
	FVector AngularVelocity = FVector::ZeroVector;

	UPROPERTY(VisibleInstanceOnly, Transient, Category = "Dynamics")
	FVector LinearAcceleration = FVector::ZeroVector;
	UPROPERTY(VisibleInstanceOnly, Transient, Category = "Dynamics")
	FVector AngularAcceleration = FVector::ZeroVector;

	FVector ForceToApply = FVector::ZeroVector;
	FVector TorqueToApply = FVector::ZeroVector;

public:	
	
	UCustomRigidbody();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// BUSINESS LOGIC

	void AddForceAtLocation(const FVector& InForce, const FVector& InAppPoint);

private:

	void Integrate(float InDeltaTime);
};