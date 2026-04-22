// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffect/Components/GEComp_GrantInputMappingContext.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemLog.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayEffect.h"
#include "InputMappingContext.h"
#include "Misc/DataValidation.h"

UGEComp_GrantInputMappingContext::UGEComp_GrantInputMappingContext()
{
#if WITH_EDITORONLY_DATA
	EditorFriendlyName = TEXT("Grant Input Mapping While Active");
#endif
}

bool UGEComp_GrantInputMappingContext::OnActiveGameplayEffectAdded(FActiveGameplayEffectsContainer& ActiveGEContainer, FActiveGameplayEffect& ActiveGE) const
{
	// return Super::OnActiveGameplayEffectAdded(ActiveGEContainer, ActiveGE);
	if (ActiveGEContainer.IsNetAuthority())
	{
		ActiveGE.EventSet.OnEffectRemoved.AddUObject(this, &ThisClass::OnActiveGameplayEffectRemoved);
		ActiveGE.EventSet.OnInhibitionChanged.AddUObject(this, &ThisClass::OnInhibitionChanged);
	}

	return true;
}

#if WITH_EDITOR
EDataValidationResult UGEComp_GrantInputMappingContext::IsDataValid(class FDataValidationContext& Context) const
{
	Super::IsDataValid(Context);

	if (GetOwner()->DurationPolicy == EGameplayEffectDurationType::Instant)
	{
		Context.AddError(FText::FromString("UInputMappingGEComp doesn't work with Duration Policy Instant"));
	}

	if (InputMappingToApply == nullptr)
	{
		Context.AddError(FText::FromString("UInputMappingGEComp must have the Input Mapping assigned"));
	}

	return (Context.GetNumErrors() > 0 ? EDataValidationResult::Invalid : EDataValidationResult::Valid);
}
#endif

void UGEComp_GrantInputMappingContext::OnInhibitionChanged(FActiveGameplayEffectHandle ActiveGEHandle, bool bIsInhibited) const
{
	if (bIsInhibited)
	{
		RemoveInputMapping(ActiveGEHandle);
	}
	else
	{
		GrantInputMapping(ActiveGEHandle);
	}
}

void UGEComp_GrantInputMappingContext::GrantInputMapping(FActiveGameplayEffectHandle ActiveGEHandle) const
{
	const UAbilitySystemComponent* ASC = ActiveGEHandle.GetOwningAbilitySystemComponent();
	if (!ensure(ASC))
	{
		UE_LOG(LogGameplayEffects, Error, TEXT("%s was passed an ActiveGEHandle %s which did not have a valid associated AbilitySystemComponent"), ANSI_TO_TCHAR(__func__), *ActiveGEHandle.ToString());
		return;
	}

	const FActiveGameplayEffect* ActiveGE = ASC->GetActiveGameplayEffect(ActiveGEHandle);
	if (!ActiveGE)
	{
		UE_LOG(LogGameplayEffects, Warning, TEXT("ActiveGEHandle %s did not corresponds to Active Gameplay Effect on %s. This could potentially happen if you remove the GE during the application of other GE's"), *ActiveGEHandle.ToString(), *ASC->GetName());
		return;
	}

	if (!ASC->AbilityActorInfo->PlayerController.IsValid())
	{
		UE_LOG(LogGameplayEffects, Error, TEXT("%s was executed on a Character without PlayerController"), ANSI_TO_TCHAR(__func__));
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ASC->AbilityActorInfo->PlayerController->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!Subsystem)
	{
		UE_LOG(LogGameplayEffects, Error, TEXT("%s was executed without UEnhancedInputLocalPlayerSubsystem"), ANSI_TO_TCHAR(__func__));
		return;
	}


	if (Subsystem->HasMappingContext(InputMappingToApply.Get()))
	{
		UE_LOG(LogGameplayEffects, Error, TEXT("%s was trying to apply the InputMapping %s but it has been already applied"), ANSI_TO_TCHAR(__func__), *GetNameSafe(InputMappingToApply.Get()));
		return;
	}

	FModifyContextOptions ModifyContextOptions;
	ModifyContextOptions.bForceImmediately = bForceImmediately;
	ModifyContextOptions.bNotifyUserSettings = bRequireInputRemapping;
	
	Subsystem->AddMappingContext(InputMappingToApply.Get(), MappingPriority, ModifyContextOptions);
}

void UGEComp_GrantInputMappingContext::RemoveInputMapping(FActiveGameplayEffectHandle ActiveGEHandle) const
{
	const UAbilitySystemComponent* ASC = ActiveGEHandle.GetOwningAbilitySystemComponent();
	if (!ensure(ASC))
	{
		UE_LOG(LogGameplayEffects, Error, TEXT("%s was passed an ActiveGEHandle %s which did not have a valid associated AbilitySystemComponent"), ANSI_TO_TCHAR(__func__), *ActiveGEHandle.ToString());
		return;
	}

	if (!ASC->AbilityActorInfo->PlayerController.IsValid())
	{
		UE_LOG(LogGameplayEffects, Error, TEXT("%s was executed on a Character without PlayerController"), ANSI_TO_TCHAR(__func__));
		return;
	}

	ULocalPlayer* LocalPlayer = ASC->AbilityActorInfo->PlayerController->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer ? LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>() : nullptr;
	if (!Subsystem)
	{
		UE_LOG(LogGameplayEffects, Error, TEXT("%s was executed without UEnhancedInputLocalPlayerSubsystem"), ANSI_TO_TCHAR(__func__));
		return;
	}

	if (Subsystem->HasMappingContext(InputMappingToApply.Get()))
	{
		Subsystem->RemoveMappingContext(InputMappingToApply.Get());
	}
}

void UGEComp_GrantInputMappingContext::OnActiveGameplayEffectRemoved(const FGameplayEffectRemovalInfo& RemovalInfo) const
{
	const FActiveGameplayEffect* ActiveGE = RemovalInfo.ActiveEffect;
	if (!ensure(ActiveGE))
	{
		UE_LOG(LogGameplayEffects, Error, TEXT("FGameplayEffectRemovalInfo::ActiveEffect was not populated in %s"), ANSI_TO_TCHAR(__func__));
		return;
	}

	RemoveInputMapping(ActiveGE->Handle);
}
