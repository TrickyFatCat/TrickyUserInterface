// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "SplashScreenWidget.generated.h"

class UImage;
class UTransitionScreenWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSplashFinishedSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSplashChangedSignature, const int32, SplashIndex);

/**
 * A widget for creation of a simple splash screen.
 */
UCLASS(Abstract)
class TRICKYUSERINTERFACE_API USplashScreenWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
public:
	/**Called when all splash screen were shown.*/
	UPROPERTY(BlueprintAssignable, Category="SplashScreen")
	FOnSplashFinishedSignature OnSplashFinished;

	/**Called when a splashscreen is changed.*/
	UPROPERTY(BlueprintAssignable, Category="SplashScreen")
	FOnSplashChangedSignature OnSplashChanged;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SplashScreen", meta=(BindWidget))
	UTransitionScreenWidget* Widget_TransitionScreen;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SplashScreen", meta=(BindWidget))
	UImage* Image_Slash = nullptr;

	/**An array of transition screens to show.*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SplashScreen")
	TArray<UTexture2D*> SplashImages;

	int32 CurrentSplashIndex = 0;

private:
	/**How long the current splash screen will be shown.*/
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category="SplashScreen",
		meta=(AllowPrivateAccess="true", ClampMin="0.25"))
	float SplashDuration = 1.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SplashScreen", meta=(AllowPrivateAccess))
	FTimerHandle SplashTimerHandle;

	UFUNCTION()
	void StartSplashTimer();

	UFUNCTION()
	void SwitchSplashScreen();
};
