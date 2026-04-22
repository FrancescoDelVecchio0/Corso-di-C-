// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/GASAbilitySystemComponent.h"


void UGASAbilitySystemComponent::InitializeComponent()
{
	//@GAS_INIT
	// OPT: if the Ability System Component is attached to the Character,
	// the Init Ability Actor Info doesn't cache correctly all its data.
	// using bBlockEarlyInitAbilityActorInfo_Ctx we are blocking the InitializeComponent.
	// in this way we will force manually the InitAbilityActor info
	// once the character is possessed (see AGASCharacter::PossessedBy)
	bBlockEarlyInitAbilityActorInfo_Ctx = true;
	Super::InitializeComponent();
	bBlockEarlyInitAbilityActorInfo_Ctx = false;
}

void UGASAbilitySystemComponent::InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
{
	//@GAS_INIT
	// Implementation of the block logics (see UGASAbilitySystemComponent::InitializeComponent)
	if (bBlockEarlyInitAbilityActorInfo_Ctx)
	{
		return;
	}
	
	Super::InitAbilityActorInfo(InOwnerActor, InAvatarActor);
}
