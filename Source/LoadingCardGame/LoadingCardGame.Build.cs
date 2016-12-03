using UnrealBuildTool;

// This module must be loaded "PreLoadingScreen" in the .uproject file, otherwise it will not hook in time!

public class LoadingCardGame : ModuleRules
{
    public LoadingCardGame(TargetInfo Target)
    {
        PrivateIncludePaths.Add("../../CardGame/Source/LoadingCardGame");

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "MoviePlayer",
                "Slate",
                "SlateCore",
                "InputCore"
            }
        );
    }
}
