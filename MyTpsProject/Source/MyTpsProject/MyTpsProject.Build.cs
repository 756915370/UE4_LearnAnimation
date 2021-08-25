// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyTpsProject : ModuleRules
{
	public MyTpsProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","UMG" });
	}
}
