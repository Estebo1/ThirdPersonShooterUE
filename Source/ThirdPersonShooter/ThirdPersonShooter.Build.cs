// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ThirdPersonShooter : ModuleRules
{
	public ThirdPersonShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ThirdPersonShooter",
			"ThirdPersonShooter/Variant_Platforming",
			"ThirdPersonShooter/Variant_Platforming/Animation",
			"ThirdPersonShooter/Variant_Combat",
			"ThirdPersonShooter/Variant_Combat/AI",
			"ThirdPersonShooter/Variant_Combat/Animation",
			"ThirdPersonShooter/Variant_Combat/Gameplay",
			"ThirdPersonShooter/Variant_Combat/Interfaces",
			"ThirdPersonShooter/Variant_Combat/UI",
			"ThirdPersonShooter/Variant_SideScrolling",
			"ThirdPersonShooter/Variant_SideScrolling/AI",
			"ThirdPersonShooter/Variant_SideScrolling/Gameplay",
			"ThirdPersonShooter/Variant_SideScrolling/Interfaces",
			"ThirdPersonShooter/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
