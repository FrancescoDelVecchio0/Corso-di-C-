using UnrealBuildTool;

public class PhysicsSandbox : ModuleRules
{
	public PhysicsSandbox(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		OptimizeCode = CodeOptimization.InShippingBuildsOnly;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"PhysicsCore",
			"Chaos",
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
