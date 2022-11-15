// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "ButtonWidget.generated.h"

class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClickSignature, class UButtonWidget*, Button);
/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API UButtonWidget : public UBaseUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="TrickyUserInterface")
	FOnClickSignature OnClicked;
	
protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta=(BindWidget))
	UButton* MainButton = nullptr;

private:
	void OnButtonClicked();
};
