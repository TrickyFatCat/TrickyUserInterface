// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "ButtonWidget.generated.h"

class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonClickedSignature, class UButtonWidget*, Button);
/**
 * 
 */
UCLASS(Abstract)
class TRICKYUSERINTERFACE_API UButtonWidget : public UBaseUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="TrickyUserInterface")
	FOnButtonClickedSignature OnButtonClicked;
	
protected:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="ButtonWidget", meta=(BindWidget))
	UButton* Button_Main = nullptr;

private:
	UFUNCTION()
	void HandleButtonClick();
};
