#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UniformAcceleration.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHYSICSSANDBOX_API UUniformAcceleration : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, Category = "Uniform Acceleration")
	FVector	Force = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Uniform Acceleration", meta = (Units = "kg"))
	float	Mass = 0.f;
	UPROPERTY(EditAnywhere, Category = "Uniform Acceleration", meta = (Units = "s"))
	float	Time = 0.f;

public:

	UUniformAcceleration();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	virtual void BeginPlay() override;
};
