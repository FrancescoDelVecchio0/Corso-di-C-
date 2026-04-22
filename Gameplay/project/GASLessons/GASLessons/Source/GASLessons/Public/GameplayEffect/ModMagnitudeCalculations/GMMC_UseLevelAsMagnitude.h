// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "GMMC_UseLevelAsMagnitude.generated.h"

/**
 * 
 */
UCLASS(meta=(DisplayName="Use Level as Magnitude"))
class GASLESSONS_API UGMMC_UseLevelAsMagnitude : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
};
