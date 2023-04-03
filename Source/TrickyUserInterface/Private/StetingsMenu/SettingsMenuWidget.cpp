// MIT License Copyright. Created by Artyom "Tricky Fat Cat" Volkov

#include "StetingsMenu/SettingsMenuWidget.h"

#include "ButtonWidget.h"
#include "GameFramework/GameUserSettings.h"


void USettingsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	QualityButtons.Add(ToRawPtr(Button_Quality_Low), 0);
	QualityButtons.Add(ToRawPtr(Button_Quality_Medium), 1);
	QualityButtons.Add(ToRawPtr(Button_Quality_High), 2);

	Button_Quality_Low->OnButtonClicked.AddDynamic(this, &USettingsMenuWidget::ApplyQuality);
	Button_Quality_Medium->OnButtonClicked.AddDynamic(this, &USettingsMenuWidget::ApplyQuality);
	Button_Quality_High->OnButtonClicked.AddDynamic(this, &USettingsMenuWidget::ApplyQuality);

	const int32 QualityIndex = UGameUserSettings::GetGameUserSettings()->GetShadowQuality();
	UButtonWidget* ButtonWidget = *QualityButtons.FindKey(QualityIndex);
	if (ButtonWidget)
	{
		ButtonWidget->SetIsEnabled(false);
	}

	ScreenModeButtons.Add(ToRawPtr(Button_ScreenMode_Window), EWindowMode::Windowed);
	ScreenModeButtons.Add(ToRawPtr(Button_ScreenMode_Full), EWindowMode::Fullscreen);

	Button_ScreenMode_Window->OnButtonClicked.AddDynamic(this, &USettingsMenuWidget::ApplyScreenMode);
	Button_ScreenMode_Full->OnButtonClicked.AddDynamic(this, &USettingsMenuWidget::ApplyScreenMode);
}

void USettingsMenuWidget::SetQualitySettings(const int32 QualityIndex)
{
	UGameUserSettings* UserSettings = UGameUserSettings::GetGameUserSettings();
	UserSettings->SetShadowQuality(QualityIndex);
	UserSettings->SetAntiAliasingQuality(QualityIndex);
	UserSettings->SetViewDistanceQuality(QualityIndex);
	UserSettings->SetTextureQuality(QualityIndex);
	UserSettings->SetViewDistanceQuality(QualityIndex);
	UserSettings->SetShadingQuality(QualityIndex);
	UserSettings->SetFoliageQuality(QualityIndex);
	UserSettings->ApplySettings(false);
}

void USettingsMenuWidget::SetScreenMode(EWindowMode::Type ScreenMode)
{
	UGameUserSettings* UserSettings = UGameUserSettings::GetGameUserSettings();
	UserSettings->SetFullscreenMode(ScreenMode);
	UserSettings->ApplySettings(false);
}


void USettingsMenuWidget::ApplyQuality(UButtonWidget* ButtonWidget)
{
	if (!ButtonWidget)
	{
		return;
	}

	const int* QualityIndex = QualityButtons.Find(ButtonWidget);

	if (!QualityIndex)
	{
		return;
	}

	SetQualitySettings(*QualityIndex);
	ButtonWidget->SetIsEnabled(false);

	for (const auto& Pair : QualityButtons)
	{
		if (Pair.Key == ButtonWidget)
		{
			continue;
		}

		Pair.Key->SetIsEnabled(true);
	}
}

void USettingsMenuWidget::ApplyScreenMode(UButtonWidget* ButtonWidget)
{
	if (!ButtonWidget)
	{
		return;
	}

	SetScreenMode(*ScreenModeButtons.Find(ButtonWidget));
	ButtonWidget->SetIsEnabled(false);
	
	for (const auto& Pair : ScreenModeButtons)
	{
		if (Pair.Key == ButtonWidget)
		{
			continue;
		}

		Pair.Key->SetIsEnabled(true);
	}
}
