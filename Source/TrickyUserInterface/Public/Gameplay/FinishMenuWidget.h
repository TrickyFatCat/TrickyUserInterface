// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "FinishMenuWidget.generated.h"

class UButtonWidget;
class UTransitionScreenWidget;

/**
 * 
 */
UCLASS(Abstract)
class TRICKYUSERINTERFACE_API UFinishMenuWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FinishScreen", meta=(BindWidget))
	UButtonWidget* Button_Continue = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FinishScreen", meta=(BindWidget))
	UButtonWidget* Button_Restart = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FinishScreen", meta=(BindWidget))
	UButtonWidget* Button_Quit = nullptr;

	UPROPERTY()
	UButtonWidget* ClickedButton = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FinishScreen", meta=(BindWidget))
	UTransitionScreenWidget* Widget_TransitionScreen = nullptr;

	UFUNCTION(BlueprintNativeEvent, Category="FinishScreen")
	void OnButtonClicked(UButtonWidget* Button);

	virtual void OnButtonClicked_Implementation(UButtonWidget* Button);

	UFUNCTION(BlueprintNativeEvent, Category="FinishScreen")
	void Continue();

	virtual void Continue_Implementation();
	
	UFUNCTION(BlueprintNativeEvent, Category="FinishScreen")
	void Restart();

	virtual void Restart_Implementation();
	
	UFUNCTION(BlueprintNativeEvent, Category="FinishScreen")
	void Quit();

	virtual void Quit_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category="FinishScreen")
	void OnTransitionScreenShowed();

	virtual void OnTransitionScreenShowed_Implementation();
};
