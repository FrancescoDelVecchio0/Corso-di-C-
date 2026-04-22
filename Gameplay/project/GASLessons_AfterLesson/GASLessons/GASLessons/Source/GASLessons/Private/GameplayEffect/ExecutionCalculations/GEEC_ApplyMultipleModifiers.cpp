// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h"

void UGEEC_ApplyMultipleModifiers::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	//BOILERPLATE CODE
	//Get the owning GameplayEffect Spec so that you can use its variables and tags.
	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	//Aggregator Evaluate Parameters used during the attribute capture.
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float CachedMagnitude = 0.f;
	ExecutionParams.AttemptCalculateTransientAggregatorMagnitude(TemporaryAggregatorTag, EvaluationParameters, CachedMagnitude);

	//Clamp Value
	switch (ClampPolicy)
	{
	case EClampType::ClampMin:
		CachedMagnitude = FMath::Min(CachedMagnitude, ClampValue);
		break;
	case EClampType::ClampMax:
		CachedMagnitude = FMath::Max(ClampValue, CachedMagnitude);
		break;
	case EClampType::ClampRange:
		CachedMagnitude = FMath::Clamp(CachedMagnitude, ClampRangeValues.X, ClampRangeValues.Y);
		break;
	default:
		break;
	}
	
	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(Attribute, ModifierOp, CachedMagnitude));
}
