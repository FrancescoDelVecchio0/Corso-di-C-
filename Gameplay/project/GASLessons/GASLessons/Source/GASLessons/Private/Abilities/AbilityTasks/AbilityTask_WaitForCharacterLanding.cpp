// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/AbilityTasks/AbilityTask_WaitForCharacterLanding.h"

#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

UAbilityTask_WaitForCharacterLanding* UAbilityTask_WaitForCharacterLanding::WaitForCharacterLanding(UGameplayAbility* OwningAbility, bool bCheckAlreadyOnGround/* = true*/)
{
	ThisClass* MyObj = NewAbilityTask<ThisClass>(OwningAbility);
	MyObj->bCheckAlreadyOnGround = bCheckAlreadyOnGround;
	return MyObj;
}

void UAbilityTask_WaitForCharacterLanding::Activate()
{
	Super::Activate();
	check(Ability);
	ACharacter* Character = Cast<ACharacter>(Ability->GetAvatarActorFromActorInfo());
	if (CanBindToCharacterLanding(Character))
	{
		Character->LandedDelegate.AddDynamic(this, &ThisClass::OnLand);
	}
	else
	{
		OnLand(FHitResult());
	}
}

bool UAbilityTask_WaitForCharacterLanding::CanBindToCharacterLanding(ACharacter* Character) const
{
	if (!Character)
	{
		return false;
	}
	if (bCheckAlreadyOnGround)
	{
		return (Character->GetMovementComponent()->IsFalling() || Character->GetMovementComponent()->IsFlying());
	}
	return true;
}

void UAbilityTask_WaitForCharacterLanding::OnDestroy(bool bInOwnerFinished)
{
	if (ACharacter* Character = Cast<ACharacter>(Ability->GetAvatarActorFromActorInfo()))
	{
		Character->LandedDelegate.RemoveAll(this);
	}
	Super::OnDestroy(bInOwnerFinished);
}

void UAbilityTask_WaitForCharacterLanding::OnLand(const FHitResult& HitResult)
{
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		OnCharacterLanded.Broadcast(HitResult);
	}
	EndTask();
}
