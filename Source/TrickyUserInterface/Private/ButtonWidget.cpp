// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "ButtonWidget.h"
#include "Components/Button.h"

void UButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button_Main->OnClicked.AddDynamic(this, &UButtonWidget::HandleButtonClick);
}

void UButtonWidget::HandleButtonClick()
{
	OnButtonClicked.Broadcast(this);
}
