// MIT License Copyright. Created by Artyom "Tricky Fat Cat" Volkov


#include "StetingsMenu/SliderWidget.h"

#include "Components/Slider.h"
#include "Components/TextBlock.h"

void USliderWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Slider_Main->OnValueChanged.AddDynamic(this, &USliderWidget::HandleValueChange);
	
}

void USliderWidget::HandleValueChange_Implementation(const float Value)
{
	const FString Text = FString::Printf(TEXT("%.2f"), Value);
	Text_Value->SetText(FText::FromString(Text));
}
