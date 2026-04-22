// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GASAttributeSet.h"
#include "CharacterAttributeSet.generated.h"

//@EXAMPLE_ATTRIBUTES: Definition
// An example of a basic AttributeSet
// In this case we are managing the health
UCLASS()
class GASLESSONS_API UCharacterAttributeSet : public UGASAttributeSet
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange_Unified(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	
	
	UPROPERTY(BlueprintReadOnly, Category="Character", ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData Health = 100.f;
	ATTRIBUTE_ACCESSORS(ThisClass, Health)

	UPROPERTY(BlueprintReadOnly, Category="Character", ReplicatedUsing=OnRep_HealthMax)
	FGameplayAttributeData HealthMax = 100.f;
	ATTRIBUTE_ACCESSORS(ThisClass, HealthMax)


	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldValue)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Health, OldValue);
	}

	UFUNCTION()
	virtual void OnRep_HealthMax(const FGameplayAttributeData& OldValue)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, HealthMax, OldValue);
	}
};
