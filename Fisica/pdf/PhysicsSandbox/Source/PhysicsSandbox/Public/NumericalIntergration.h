#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NumericalIntergration.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHYSICSSANDBOX_API UNumericalIntergration : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, Category = "Uniform Acceleration")
	FVector	Force = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Uniform Acceleration", meta = (Units = "kg"))
	float	Mass = 0.f;
	UPROPERTY(EditAnywhere, Category = "Uniform Acceleration", meta = (Units = "s"))
	float	Time = 0.f;
	UPROPERTY(EditAnywhere, Category = "Uniform Acceleration", meta = (Units = "s"))
	float	TimeStep = 0.f;

public:	

	UNumericalIntergration();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	virtual void BeginPlay() override;
};