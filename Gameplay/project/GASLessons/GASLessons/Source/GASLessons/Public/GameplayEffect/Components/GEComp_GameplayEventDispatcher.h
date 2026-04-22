// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectComponent.h"
#include "GameplayTagContainer.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "GEComp_GameplayEventDispatcher.generated.h"


UENUM()
enum class EEventTargetType : uint8
{
	/**Event will be sent only to the Source of the Gameplay Effect, if available*/
	Source,
	/**Event will be sent only to the Target of the Gameplay Effect*/
	Target,
	/**Event will be sent both to the Source and the Target of the Gameplay Effect*/
	Both
};

/**
 * 
 */
UCLASS(Abstract)
class GASLESSONS_API UGEComp_GameplayEventDispatcher : public UGameplayEffectComponent
{
	GENERATED_BODY()

public:
	virtual FGameplayEventData CreateEventFromSpec(const FGameplayEffectSpec &Spec, UAbilitySystemComponent* Owner) const;
	int32 DispatchEventFromSpec(FGameplayEventData* EventToSend, const FGameplayEffectSpec &Spec, UAbilitySystemComponent* Owner, const EEventTargetType TargetType) const;
	int32 CreateAndDispatchEventFromSpec(const FGameplayEffectSpec &Spec, UAbilitySystemComponent* Owner, const EEventTargetType TargetType) const;
	
};

UCLASS()
class GASLESSONS_API UGEComp_GameplayEventDispatcherSimpleTag : public UGEComp_GameplayEventDispatcher
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, Category = Event)
	FGameplayTag EventTag;
	UPROPERTY(EditDefaultsOnly, Category = Event)
	EEventTargetType TargetType;
	UPROPERTY(EditDefaultsOnly, Category = Event)
	FGameplayAttribute MagnitudeAttribute;
	
	virtual FGameplayEventData CreateEventFromSpec(const FGameplayEffectSpec& Spec, UAbilitySystemComponent* Owner) const override;
	virtual void OnGameplayEffectExecuted(FActiveGameplayEffectsContainer& ActiveGEContainer, FGameplayEffectSpec& GESpec, FPredictionKey& PredictionKey) const override;
};