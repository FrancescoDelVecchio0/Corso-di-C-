// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSets/CharacterAttributeSet.h"

#include "Net/UnrealNetwork.h"

void UCharacterAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, HealthMax, COND_None, REPNOTIFY_Always);
}

void UCharacterAttributeSet::PreAttributeChange_Unified(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeChange_Unified(Attribute, NewValue);

	if (Attribute == GetHealthMaxAttribute())
	{
		if (NewValue < 0.f)
		{
			NewValue = 0.f;
		}
	}

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetHealthMax());
	}
}

void UCharacterAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	if (Attribute == GetHealthMaxAttribute())
	{
		if (NewValue < GetHealth())
		{
			SetHealth(NewValue);
		}
	}
}