// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "ButtonWidget.h"
#include "MainMenuWidget.generated.h"

class UTransitionScreenWidget;
class UButtonWidget;

/**
 * A widget for creation of a simple main menu.
 */
UCLASS(Abstract)
class TRICKYUSERINTERFACE_API UMainMenuWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MainMenu", meta=(BindWidget))
	UTransitionScreenWidget* Widget_TransitionScreen;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MainMenu", meta=(BindWidget))
	UButtonWidget* Button_Quit = nullptr;

	/**Called when the transition screen finishes its show animation.*/
	UFUNCTION(BlueprintNativeEvent, Category="TrickyUserInterface")
	void OnTransitionScreenShowed();

	virtual void OnTransitionScreenShowed_Implementation();

	/**Called when the transition screen finishes its hide animation.*/
	UFUNCTION(BlueprintNativeEvent, Category="TrickyUserInterface")
	void OnTransitionScreenHidden();

	virtual void OnTransitionScreenHidden_Implementation();

private:
	bool bMustBeQuit = false;
	
	UFUNCTION()
	void QuitGame(UButtonWidget* Button);
};
