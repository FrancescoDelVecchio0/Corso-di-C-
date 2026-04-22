// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffect/ModMagnitudeCalculations/GMMC_UseLevelAsMagnitude.h"

float UGMMC_UseLevelAsMagnitude::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	return Spec.GetLevel();
}
