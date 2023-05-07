// MIT License Copyright. Created by Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "SettingsMenuWidget.generated.h"

class UButtonWidget;
class USliderWidget;
class USoundSliderWidget;

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API USettingsMenuWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_ScreenMode_Full = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_ScreenMode_Window = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_Quality_Low = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_Quality_Medium = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_Quality_High = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_Quality_Epic = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_Quit = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<USliderWidget> Slider_ResolutionScale = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<USoundSliderWidget> Slider_MasterSound = nullptr;

public:
	UFUNCTION(BlueprintCallable)
	static void SetQualitySettings(const int32 QualityIndex);

	UFUNCTION(BlueprintCallable)
	static void SetScreenMode(EWindowMode::Type ScreenMode);

	UFUNCTION(BlueprintCallable)
	static void SetResolutionScale(const float Scale = 1.f);

private:
	UPROPERTY()
	TObjectPtr<UButtonWidget> CurrentQualityButton = nullptr;

	UPROPERTY()
	TObjectPtr<UButtonWidget> CurrentScreenModeButton = nullptr;

	UFUNCTION()
	void ApplyQuality(UButtonWidget* ButtonWidget);

	UFUNCTION()
	void ApplyScreenMode(UButtonWidget* ButtonWidget);

	UFUNCTION()
	void ApplyResolutionScale(const float Value);
};
