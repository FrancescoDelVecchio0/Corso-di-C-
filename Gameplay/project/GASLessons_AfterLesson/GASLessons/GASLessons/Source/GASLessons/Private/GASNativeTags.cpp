// Fill out your copyright notice in the Description page of Project Settings.


#include "GASNativeTags.h"

#include "NativeGameplayTags.h"

//@EXAMPLE_TAGS: Definition
namespace Tags
{
	namespace Action
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Root, "Action", "Root Tag that identifies the Actions");
	}

	namespace Event
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Root, "Event", "Root Tag that identifies the Gameplay Events");

		namespace Example
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(JumpLanded, "Event.Example.JumpLanded", "Example tag for an event triggered when the character lands after a jump");
		}
	}

	namespace State
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Root, "State", "Root Tag that identifies a state when applied");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(InAir, "State.InAir", "Example tag that identifies a Character is in air and not on the ground");
	}
}
