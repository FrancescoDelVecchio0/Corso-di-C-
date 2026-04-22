// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/GASAIController.h"

#include "GASCharacter.h"

UAbilitySystemComponent* AGASAIController::GetAbilitySystemComponent() const
{
	if (GASCharacter)
	{
		return GASCharacter->GetAbilitySystemComponent();
	}
	return nullptr;
}


void AGASAIController::OnPossess(APawn* InPawn)
{
	GASCharacter = Cast<AGASCharacter>(InPawn);

	Super::OnPossess(InPawn);
}

void AGASAIController::OnUnPossess()
{
	Super::OnUnPossess();
	
	GASCharacter = nullptr;
}
