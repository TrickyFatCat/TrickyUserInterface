﻿// MIT License Copyright. Created by Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "Components/Slider.h"
#include "SliderWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API USliderWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;
	
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, Category="Slider", meta=(BindWidget))
	TObjectPtr<USlider> Slider_Main = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category="Slider", meta=(BindWidget))
	TObjectPtr<UTextBlock> Text_Value = nullptr;

	UFUNCTION()
	void ChangeValue(const float Value);

	UFUNCTION(BlueprintNativeEvent, Category="Slider")
	void HandleValueChange(const float Value);

	virtual void HandleValueChange_Implementation(const float Value);
	
public:
	UPROPERTY(BlueprintAssignable)
	FOnFloatValueChangedEvent OnValueChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slider")
	float InitialValue = 1.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slider")
	float MinValue = 0.0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slider")
	float MaxValue = 1.0;
	
	UFUNCTION(BlueprintCallable, Category="Slider")
	void SetValue(const float Value);

private:
	void SetTextValue(const float Value) const;
};
