// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/GASPlayerController.h"

#include "GASCharacter.h"

UAbilitySystemComponent* AGASPlayerController::GetAbilitySystemComponent() const
{
	if (GASCharacter)
	{
		return GASCharacter->GetAbilitySystemComponent();
	}
	return nullptr;
}

void AGASPlayerController::OnPossess(APawn* InPawn)
{
	GASCharacter = Cast<AGASCharacter>(InPawn);

	Super::OnPossess(InPawn);
}

void AGASPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
	
	GASCharacter = nullptr;
}
