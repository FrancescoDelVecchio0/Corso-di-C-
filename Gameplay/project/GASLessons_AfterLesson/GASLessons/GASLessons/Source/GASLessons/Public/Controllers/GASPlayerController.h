// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerController.h"
#include "GASPlayerController.generated.h"

class AGASCharacter;
/**
 * 
 */
UCLASS()
class GASLESSONS_API AGASPlayerController : public APlayerController, public IAbilitySystemInterface //@GAS_INTERFACE - added interface
{
	GENERATED_BODY()

protected:
	//@GAS_INTERFACE
	// caching the Character instead of the AbilitySystemComponent because
	// we are assuming that the Character may be expanded for the project
	// so it might be used from other purposes
	UPROPERTY()
	TObjectPtr<AGASCharacter> GASCharacter;

public:
	//@GAS_INTERFACE - Declaration of the interface function
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
};
