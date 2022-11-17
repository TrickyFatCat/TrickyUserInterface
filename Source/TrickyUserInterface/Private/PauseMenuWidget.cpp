// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "PauseMenuWidget.h"

#include "TransitionScreenWidget.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
}


void UPauseMenuWidget::ActivateTransition_Implementation(UButtonWidget* Button)
{
	if (Button == ResumeButton)
	{
		Hide();
	}
	else if (Button == RestartButton || Button == QuitButton)
	{
		ClickedButton = Button;
		TransitionScreenWidget->Show();
	}
}

void UPauseMenuWidget::Restart_Implementation()
{
	const FName CurrentLevelName = FName(UGameplayStatics::GetCurrentLevelName(this));
	UGameplayStatics::OpenLevel(this, CurrentLevelName);
}

void UPauseMenuWidget::Quit_Implementation()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

void UPauseMenuWidget::TransitionScreenShowed_Implementation()
{
	if (ClickedButton == RestartButton)
	{
		Restart();
	}
	else if (ClickedButton == QuitButton)
	{
		Quit();
	}
}
