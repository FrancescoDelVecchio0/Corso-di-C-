// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSets/GASAttributeSet.h"

void UGASAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	PreAttributeChange_Unified(Attribute, NewValue);
}

void UGASAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);
	PreAttributeChange_Unified(Attribute, NewValue);
}

void UGASAttributeSet::PreAttributeChange_Unified(const FGameplayAttribute& Attribute, float& NewValue) const
{
}
