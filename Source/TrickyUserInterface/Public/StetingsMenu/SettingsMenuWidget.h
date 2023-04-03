// MIT License Copyright. Created by Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "SettingsMenuWidget.generated.h"

class UButtonWidget;

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API USettingsMenuWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_ScreenMode_Full = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_ScreenMode_Window = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_Quality_Low = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_Quality_Medium = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_Quality_High = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SetittingsMenu", meta=(BindWidget))
	TObjectPtr<UButtonWidget> Button_Quit = nullptr;

public:
	UFUNCTION(BlueprintCallable)
	static void SetQualitySettings(const int32 QualityIndex);

	UFUNCTION(BlueprintCallable)
	static void SetScreenMode(EWindowMode::Type ScreenMode);

private:
	UPROPERTY()
	TMap<UButtonWidget*, int32> QualityButtons;

	UFUNCTION()
	void ApplyQuality(UButtonWidget* ButtonWidget);

	UPROPERTY()
	TMap<UButtonWidget*, TEnumAsByte<EWindowMode::Type>> ScreenModeButtons;

	UFUNCTION()
	void ApplyScreenMode(UButtonWidget* ButtonWidget);
};
