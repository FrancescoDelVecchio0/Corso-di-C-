// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GASLessons : ModuleRules
{
	public GASLessons(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"AIModule",
			"GameplayAbilities",//@GAS_SETUP
			"GameplayTasks",//@GAS_SETUP
			"GameplayTags", //@GAS_SETUP
		});
	}
}
