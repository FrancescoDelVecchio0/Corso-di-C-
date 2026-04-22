// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectComponent.h"
#include "GEComp_GrantInputMappingContext.generated.h"

struct FActiveGameplayEffectHandle;
struct FGameplayEffectRemovalInfo;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class GASLESSONS_API UGEComp_GrantInputMappingContext : public UGameplayEffectComponent
{
	GENERATED_BODY()

public:
	UGEComp_GrantInputMappingContext();

	virtual bool OnActiveGameplayEffectAdded(FActiveGameplayEffectsContainer& ActiveGEContainer, FActiveGameplayEffect& ActiveGE) const override;
	
#if WITH_EDITOR
	/** Warn on misconfigured Gameplay Effect */
	virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif

protected:
	/** This allows us to be notified when the owning GameplayEffect has had its inhibition changed (which can happen on the initial application). */
	virtual void OnInhibitionChanged(FActiveGameplayEffectHandle ActiveGEHandle, bool bIsInhibited) const;

	/** We should grant the configured Gameplay Abilities */
	virtual void GrantInputMapping(FActiveGameplayEffectHandle ActiveGEHandle) const;

	/** We should remove the configured Gameplay Abilities */
	virtual void RemoveInputMapping(FActiveGameplayEffectHandle ActiveGEHandle) const;

private:
	/** We must undo all effects when removed */
	void OnActiveGameplayEffectRemoved(const FGameplayEffectRemovalInfo& RemovalInfo) const;


protected:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	TObjectPtr<UInputMappingContext> InputMappingToApply;
	
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool bForceImmediately = false;
	
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool bRequireInputRemapping = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Settings", meta=(ClampMin="0"))
	int32 MappingPriority = 0;
};
