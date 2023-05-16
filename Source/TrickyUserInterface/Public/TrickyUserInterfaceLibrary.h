// MIT License Copyright. Created by Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TrickyUserInterfaceLibrary.generated.h"

UENUM(BlueprintType)
enum class ETimeFormat : uint8
{
	MM_SS_MsMs UMETA(DisplayName="MM:SS.MsMs"),
	MM_SS_Ms UMETA(DisplayName="MM:SS.Ms"),
	MM_SS UMETA(DisplayName="MM:SS"),
	SS_MsMs UMETA(DisplayName="SS.MsMs"),
	SS_Ms UMETA(DisplayName="SS.Ms"),
	SS UMETA(DisplayName="SS")
};

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API UTrickyUserInterfaceLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="TrickyUserInterface")
	static void SetQualitySettings(const int32 QualityIndex);

	UFUNCTION(BlueprintCallable, Category="TrickyUserInterface")
	static void SetScreenMode(EWindowMode::Type ScreenMode);

	UFUNCTION(BlueprintCallable, Category="TrickyUserInterface")
	static void SetResolutionScale(const float Scale = 1.f);

	UFUNCTION(BlueprintPure, Category="TrickyUserInterface")
	static void SetResolution(const int32 Width, const int32 Height);
	
	UFUNCTION(BlueprintPure, Category="TrickyUserInterface")
	static FString ConvertTimeSeconds(const float TimeSeconds, const ETimeFormat TimeFormat);
};
