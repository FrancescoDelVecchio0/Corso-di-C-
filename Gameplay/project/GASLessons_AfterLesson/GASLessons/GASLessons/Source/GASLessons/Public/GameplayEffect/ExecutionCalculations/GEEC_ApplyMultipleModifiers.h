// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEEC_ApplyMultipleModifiers.generated.h"

UENUM()
enum class EClampType : uint8
{
	None = 0,
	ClampMin = 1,
	ClampMax = 2,
	ClampRange = 3,
};


/**
 * 
 */
UCLASS(Abstract, meta=(DisplayName="Apply Multiple Modifiers"))
class GASLESSONS_API UGEEC_ApplyMultipleModifiers : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag TemporaryAggregatorTag;
	
	UPROPERTY(EditDefaultsOnly)
	FGameplayAttribute Attribute;

	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<EGameplayModOp::Type> ModifierOp;

	UPROPERTY(EditDefaultsOnly)
	EClampType ClampPolicy = EClampType::None;

	UPROPERTY(EditDefaultsOnly, meta=(EditCondition="ClampPolicy != EClampType::ClampRange", EditConditionHides))
	float ClampValue;

	UPROPERTY(EditDefaultsOnly, meta=(EditCondition="ClampPolicy == EClampType::ClampRange", EditConditionHides, XAxisName="Min", YAxisName="Max"))
	FVector2D ClampRangeValues;
	
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
