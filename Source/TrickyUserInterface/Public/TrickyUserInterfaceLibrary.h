// MIT License Copyright. Created by Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TrickyUserInterfaceLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API UTrickyUserInterfaceLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Settings")
    	static void SetQualitySettings(const int32 QualityIndex);
    
    	UFUNCTION(BlueprintCallable, Category="Settings")
    	static void SetScreenMode(EWindowMode::Type ScreenMode);
    
    	UFUNCTION(BlueprintCallable, Category="Settings")
    	static void SetResolutionScale(const float Scale = 1.f);
};
