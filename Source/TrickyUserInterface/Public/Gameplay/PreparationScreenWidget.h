// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "PreparationScreenWidget.generated.h"

class UTransitionScreenWidget;
class UTextBlock;

/**
 * 
 */
UCLASS(Abstract)
class TRICKYUSERINTERFACE_API UPreparationScreenWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PreparationScreen", meta=(BindWidget))
	UTransitionScreenWidget* Widget_TransitionScreen = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PreparationScreen", meta=(BindWidget))
	UTextBlock* Text_PreparationTimer = nullptr;
};
