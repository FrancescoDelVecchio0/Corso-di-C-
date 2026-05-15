#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomRigidbody.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHYSICSSANDBOX_API UCustomRigidbody : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UCustomRigidbody();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// BUSINESS LOGIC

	void AddForceAtLocation(const FVector& InForce, const FVector& InAppPoint);

private:

	void Integrate(float InDeltaTime);
};