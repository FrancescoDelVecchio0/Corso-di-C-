// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

//@EXAMPLE_TAGS: Declaration
namespace Tags
{
	namespace Action
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Root)
	}

	namespace Event
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Root)

		namespace Example
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(JumpLanded);
		}
	}

	namespace State
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Root)
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(InAir)
	}
}
