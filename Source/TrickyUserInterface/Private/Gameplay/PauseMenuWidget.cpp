// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov


#include "Gameplay/PauseMenuWidget.h"

#include "ButtonWidget.h"
#include "TransitionScreenWidget.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	auto BindButtonEvent = [&](UButtonWidget* ButtonWidget)
	{
		ButtonWidget->OnButtonClicked.AddDynamic(this, &UPauseMenuWidget::OnButtonClick);
	};

	BindButtonEvent(ToRawPtr(Button_Resume));
	BindButtonEvent(ToRawPtr(Button_Restart));
	BindButtonEvent(ToRawPtr(Button_Quit));
	Widget_TransitionScreen->OnShowed.AddDynamic(this, &UPauseMenuWidget::TransitionScreenShowed);
}

void UPauseMenuWidget::OnButtonClick_Implementation(UButtonWidget* Button)
{
	if (Button == Button_Resume)
	{
		Hide();
		UGameplayStatics::SetGamePaused(this,false);
	}
	else if (Button == Button_Restart || Button == Button_Quit)
	{
		ClickedButton = Button;
		Widget_TransitionScreen->Show();
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
	if (ClickedButton == Button_Restart)
	{
		Restart();
	}
	else if (ClickedButton == Button_Quit)
	{
		Quit();
	}
}
