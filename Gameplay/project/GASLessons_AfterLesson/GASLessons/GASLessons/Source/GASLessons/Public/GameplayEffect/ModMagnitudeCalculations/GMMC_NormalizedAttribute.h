// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "GMMC_NormalizedAttribute.generated.h"

/**
 * 
 */
UCLASS(Abstract, meta=(DisplayName="Normalized Attribute"))
class GASLESSONS_API UGMMC_NormalizedAttribute : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	int32 CurrentAttributeIndex = 0;
	
	UPROPERTY(EditDefaultsOnly)
	int32 MaxAttributeIndex = 1;

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
};
