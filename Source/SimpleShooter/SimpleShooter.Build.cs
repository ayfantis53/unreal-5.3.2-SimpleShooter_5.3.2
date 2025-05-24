// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SimpleShooter : ModuleRules
{
	public SimpleShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", 
															"CoreUObject", 
															"Engine", 
															"InputCore", 
															"EnhancedInput", 
															"GameplayTasks", 
															"AIModule" });

		//PrivateDependencyModuleNames.AddRange(new string[] {  });

		//  List of all paths to include files that are exposed to other modules
		/*PublicIncludePaths.AddRange(new string[] { "SimpleShooter/Public/AI",
												   "SimpleShooter/Public/Characters",
												   "SimpleShooter/Public/Components",
												   "SimpleShooter/Public/FX",
												   "SimpleShooter/Public/GameModes",
												   "SimpleShooter/Public/UI",
												   "SimpleShooter/Public/Weapons",
		});*/

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", 
															 "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
