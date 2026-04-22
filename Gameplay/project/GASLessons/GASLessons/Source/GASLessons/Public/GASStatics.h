// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect/Components/GEComp_GameplayEventDispatcher.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GASStatics.generated.h"

struct FGameplayEffectSpec;
struct FGameplayAbilitySpecHandle;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class GASLESSONS_API UGASStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static void SetRemoveAbilityOnEnd(UAbilitySystemComponent* ASC, FGameplayAbilitySpecHandle SpecHandle);
	static FGameplayEventData MakeEventDataFromGameplayEffectSpec(const FGameplayEffectSpec& Spec, AActor* TargetActor);
};
