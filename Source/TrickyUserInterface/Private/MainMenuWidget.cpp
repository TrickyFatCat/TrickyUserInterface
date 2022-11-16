// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "MainMenuWidget.h"

#include "ButtonWidget.h"
#include "TransitionScreenWidget.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::QuitGame);
	TransitionScreen->OnShowed.AddDynamic(this, &UMainMenuWidget::OnTransitionScreenShowed);
}

void UMainMenuWidget::OnTransitionScreenShowed_Implementation()
{
	if (bMustBeQuit)
	{
		UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
	}
}

void UMainMenuWidget::OnTransitionScreenHidden_Implementation()
{
}

void UMainMenuWidget::QuitGame(UButtonWidget* Button)
{
	TransitionScreen->Show();
}
