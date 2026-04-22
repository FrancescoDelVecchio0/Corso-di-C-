// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GASAttributeSet.generated.h"

//@GAS_TIPS#2
// Macro defined in order to create the basic accessors for a Gameplay Attribute
// from UE 5.6 unreal have defined it inside the engine: ATTRIBUTE_ACCESSORS_BASIC
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS(Abstract)
class GASLESSONS_API UGASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	//@GAS_TIPS#4
	// in order to apply the same logics both to the Base Value
	// and the Current Value we have created a _Unified version,
	// and it is called in both the scopes
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PreAttributeChange_Unified(const FGameplayAttribute& Attribute, float& NewValue) const;
};
