// Fill out your copyright notice in the Description page of Project Settings.


#include "GASStatics.h"

#include "AbilitySystemComponent.h"
#include "GameplayAbilitySpecHandle.h"

void UGASStatics::SetRemoveAbilityOnEnd(UAbilitySystemComponent* ASC, FGameplayAbilitySpecHandle SpecHandle)
{
	if (!ASC)
	{
		return;
	}
	
	FGameplayAbilitySpec* FoundSpec = ASC->FindAbilitySpecFromHandle(SpecHandle, EConsiderPending::PendingAdd);
	if (!FoundSpec)
	{
		return;
	}
	
	if (FoundSpec->IsActive())
	{
		FoundSpec->RemoveAfterActivation = true;
	}
	else
	{
		ASC->ClearAbility(SpecHandle);
	}
}

FGameplayEventData UGASStatics::MakeEventDataFromGameplayEffectSpec(const FGameplayEffectSpec& Spec, AActor* TargetActor)
{
	FGameplayEventData EventData;
	EventData.Instigator = Spec.GetEffectContext().GetInstigator();
	EventData.Target = TargetActor;
	EventData.ContextHandle = Spec.GetContext();
	EventData.InstigatorTags = *Spec.CapturedSourceTags.GetAggregatedTags();
	EventData.TargetTags = *Spec.CapturedTargetTags.GetAggregatedTags();
	return MoveTemp(EventData);
}
