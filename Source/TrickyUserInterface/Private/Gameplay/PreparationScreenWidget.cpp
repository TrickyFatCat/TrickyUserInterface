// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "Gameplay/PreparationScreenWidget.h"

#include "TransitionScreenWidget.h"

void UPreparationScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();
	Widget_TransitionScreen->Hide();
}

