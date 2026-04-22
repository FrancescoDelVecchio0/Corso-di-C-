// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameplayCueInterface.h"
#include "GASLessons/GASLessonsCharacter.h"
#include "GASCharacter.generated.h"

class UGASAbilitySystemComponent;

UCLASS()
class GASLESSONS_API AGASCharacter : public AGASLessonsCharacter, public IAbilitySystemInterface //@GAS_INTERFACE - added interface
{
	GENERATED_BODY()

public:
	//@GAS_INTERFACE - defined CTOR for setup ASC property
	AGASCharacter(const FObjectInitializer& ObjectInitializer);
	
protected:
	//@GAS_INTERFACE - Ability System Component Property (already using an inherited version in order to allow overrides via code)
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UGASAbilitySystemComponent> AbilitySystemComponent;

public:
	//@GAS_INTERFACE - Declaration of the interface function
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;


	virtual void PossessedBy(AController* NewController) override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode = 0) override;


protected:
	//EXAMPLES
	// these are functions and properties with the only purpose to have
	// a valid context in order to understand how to manage stuff
	// with the AbilitySystem
	void Example_BeginPlay();
	void Example_EndPlay();
	void Example_OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode = 0);

	UPROPERTY(EditDefaultsOnly)
	FGameplayCueTag Example_CueTag;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayAbility> Example_GAClass;

	bool bRunExampleBeginPlay = false;
	bool bRunExampleEndPlay = false;
	bool bRunExampleMovementModeFake = false;
	FDelegateHandle Example_InAirTagHandle;
	FDelegateHandle Example_HealthAttHandle;
	FGameplayAbilitySpecHandle Example_GASpecHandle;
};
