// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffect/Components/GEComp_GameplayEventDispatcher.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GASStatics.h"
#include "Abilities/GameplayAbilityTypes.h"

FGameplayEventData UGEComp_GameplayEventDispatcher::CreateEventFromSpec(const FGameplayEffectSpec& Spec, UAbilitySystemComponent* Owner) const
{
	return UGASStatics::MakeEventDataFromGameplayEffectSpec(Spec, Owner->GetAvatarActor());
}

int32 UGEComp_GameplayEventDispatcher::DispatchEventFromSpec(FGameplayEventData* EventToSend, const FGameplayEffectSpec& Spec, UAbilitySystemComponent* Owner, const EEventTargetType TargetType) const
{
	int32 TriggeredAbilities = 0;
	if (EventToSend && EventToSend->EventTag.IsValid())
	{
		//is Target or Both
		if (TargetType != EEventTargetType::Source)
		{
			check(Owner);
			TriggeredAbilities += Owner->HandleGameplayEvent(EventToSend->EventTag, EventToSend);
		}

		//is Source or Both
		if (TargetType != EEventTargetType::Target)
		{
			if (UAbilitySystemComponent* SourceASC = Spec.GetEffectContext().GetInstigatorAbilitySystemComponent())
			{
				TriggeredAbilities += SourceASC->HandleGameplayEvent(EventToSend->EventTag, EventToSend);
			}
		}
	}
	return TriggeredAbilities;
}

int32 UGEComp_GameplayEventDispatcher::CreateAndDispatchEventFromSpec(const FGameplayEffectSpec& Spec, UAbilitySystemComponent* Owner, const EEventTargetType TargetType) const
{
	FGameplayEventData EventData = CreateEventFromSpec(Spec, Owner);
	return DispatchEventFromSpec(&EventData, Spec, Owner, TargetType);
}


FGameplayEventData UGEComp_GameplayEventDispatcherSimpleTag::CreateEventFromSpec(const FGameplayEffectSpec& Spec, UAbilitySystemComponent* Owner) const
{
	if (EventTag.IsValid())
	{
		FGameplayEventData EventData = Super::CreateEventFromSpec(Spec, Owner);
		EventData.EventTag = EventTag;
		if(MagnitudeAttribute.IsValid())
		{
			for (const FGameplayEffectModifiedAttribute& ModifiedAttribute : Spec.ModifiedAttributes)
			{
				if (ModifiedAttribute.Attribute == MagnitudeAttribute)
				{
					EventData.EventMagnitude = ModifiedAttribute.TotalMagnitude;
					break;
				}
			}
		}
		return MoveTemp(EventData);
	}
	return FGameplayEventData();
}

void UGEComp_GameplayEventDispatcherSimpleTag::OnGameplayEffectExecuted(FActiveGameplayEffectsContainer& ActiveGEContainer, FGameplayEffectSpec& GESpec, FPredictionKey& PredictionKey) const
{
	Super::OnGameplayEffectExecuted(ActiveGEContainer, GESpec, PredictionKey);
	CreateAndDispatchEventFromSpec(GESpec, ActiveGEContainer.Owner, TargetType);
}

