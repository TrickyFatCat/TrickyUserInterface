// MIT License Copyright. Created by Artyom "Tricky Fat Cat" Volkov


#include "TrickyUserInterfaceLibrary.h"

#include "GameFramework/GameUserSettings.h"

void UTrickyUserInterfaceLibrary::SetQualitySettings(const int32 QualityIndex)
{
	if (QualityIndex < 0 || QualityIndex > 3)
	{
		return;
	}

	UGameUserSettings* UserSettings = UGameUserSettings::GetGameUserSettings();

	UserSettings->SetViewDistanceQuality(QualityIndex);
	UserSettings->SetAntiAliasingQuality(QualityIndex);
	UserSettings->SetPostProcessingQuality(QualityIndex);
	UserSettings->SetShadowQuality(QualityIndex);
	UserSettings->SetGlobalIlluminationQuality(QualityIndex);
	UserSettings->SetReflectionQuality(QualityIndex);
	UserSettings->SetTextureQuality(QualityIndex);
	UserSettings->SetFoliageQuality(QualityIndex);
	UserSettings->SetVisualEffectQuality(QualityIndex);
	UserSettings->SetShadingQuality(QualityIndex);

	UserSettings->ApplySettings(false);
}

void UTrickyUserInterfaceLibrary::SetScreenMode(EWindowMode::Type ScreenMode)
{
	UGameUserSettings* UserSettings = UGameUserSettings::GetGameUserSettings();
	UserSettings->SetFullscreenMode(ScreenMode);

	FIntPoint DesktopResolution = UserSettings->GetDesktopResolution();

	if (ScreenMode == EWindowMode::Windowed)
	{
		DesktopResolution.X *= 0.75;
		DesktopResolution.Y *= 0.75;
	}

	UserSettings->SetScreenResolution(DesktopResolution);
	UserSettings->ApplySettings(false);
	UserSettings->ApplyResolutionSettings(false);
}

void UTrickyUserInterfaceLibrary::SetResolutionScale(const float Scale)
{
	if (Scale < 0.f || Scale > 1.0)
	{
		return;
	}

	UGameUserSettings* UserSettings = UGameUserSettings::GetGameUserSettings();

	UserSettings->SetResolutionScaleNormalized(Scale);
	UserSettings->ApplySettings(false);
}
