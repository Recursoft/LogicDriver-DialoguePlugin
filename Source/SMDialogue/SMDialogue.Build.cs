// Copyright Recursoft LLC 2019-2020. All Rights Reserved.
using UnrealBuildTool;
using System.IO;


public class SMDialogue : ModuleRules
{
	public SMDialogue(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
                Path.Combine(ModuleDirectory, "Public"),
                Path.Combine(ModuleDirectory, "Public", "Nodes"),
                Path.Combine(ModuleDirectory, "Public", "Nodes", "States"),
                Path.Combine(ModuleDirectory, "Public", "Nodes", "Transitions"),
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
                Path.Combine(ModuleDirectory, "Private")
				// ... add other private include paths required here ...
			}
			);

        PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
                "SMSystem",
                "SMExtendedRuntime"
				// ... add other public dependencies that you statically link with here ...
			}
			);
   
        if (Target.Type == TargetType.Editor)
        {
            PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "SlateCore",
            }
            );
        }

        PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
