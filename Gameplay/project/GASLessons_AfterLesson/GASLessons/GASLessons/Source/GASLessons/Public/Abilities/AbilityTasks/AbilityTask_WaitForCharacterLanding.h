// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_WaitForCharacterLanding.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWaitForLandingDelegate, const FHitResult&, Hit);

/**
 * 
 */
UCLASS()
class GASLESSONS_API UAbilityTask_WaitForCharacterLanding : public UAbilityTask
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FWaitForLandingDelegate OnCharacterLanded;

	/**
	* Wait until the specified gameplay tag event is triggered. By default this will look at the owner of this ability. OptionalExternalTarget can be set to make this look at another actor's tags for changes
	* It will keep listening as long as OnlyTriggerOnce = false
	* If OnlyMatchExact = false it will trigger for nested tags
	*/
	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UAbilityTask_WaitForCharacterLanding* WaitForCharacterLanding(UGameplayAbility* OwningAbility, bool bCheckAlreadyOnGround = true);

private:
	virtual void Activate() override;
	bool CanBindToCharacterLanding(ACharacter* Character) const;
	virtual void OnDestroy(bool bInOwnerFinished) override;

	UFUNCTION()
	void OnLand(const FHitResult& HitResult);

	UPROPERTY()
	bool bCheckAlreadyOnGround = true;

};
