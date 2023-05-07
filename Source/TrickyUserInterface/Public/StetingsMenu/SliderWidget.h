// MIT License Copyright. Created by Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "SliderWidget.generated.h"

class USlider;
class UTextBlock;

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API USliderWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Slider", meta=(BindWidget))
	TObjectPtr<USlider> Slider_Main = nullptr;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Slider", meta=(BindWidget))
	TObjectPtr<UTextBlock> Text_Value = nullptr;

	UFUNCTION(BlueprintNativeEvent, Category="Slider")
	void HandleValueChange(const float Value);

	virtual void HandleValueChange_Implementation(const float Value);
};
