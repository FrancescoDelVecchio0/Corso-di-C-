// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffect/ModMagnitudeCalculations/GMMC_NormalizedAttribute.h"

#include "AbilitySystemLog.h"

float UGMMC_NormalizedAttribute::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluationParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	if (!RelevantAttributesToCapture.IsValidIndex(MaxAttributeIndex) || !RelevantAttributesToCapture.IsValidIndex(CurrentAttributeIndex))
	{
		ABILITY_LOG(Warning, TEXT("Cannot normalize the attributes because the indexes are invalid. Aborting."))
		return 0.f;
	}

	const FGameplayEffectAttributeCaptureSpec* CaptureSpecMax = Spec.CapturedRelevantAttributes.FindCaptureSpecByDefinition(RelevantAttributesToCapture[MaxAttributeIndex], true);

	float NormalizedValue = 0.f;

	float MaxValue = 0.f;
	CaptureSpecMax->AttemptCalculateAttributeMagnitude(EvaluationParameters, MaxValue);

	if (MaxValue > 0.f)
	{
		const FGameplayEffectAttributeCaptureSpec* CaptureSpecCurrent = Spec.CapturedRelevantAttributes.FindCaptureSpecByDefinition(RelevantAttributesToCapture[CurrentAttributeIndex], true);

		float CurrentValue = 0.f;
		CaptureSpecCurrent->AttemptCalculateAttributeMagnitude(EvaluationParameters, CurrentValue);
		NormalizedValue = FMath::Min(CurrentValue / MaxValue, 1.f); //IDK why but the normalization goes over 1.f
	}

	return NormalizedValue;
}
