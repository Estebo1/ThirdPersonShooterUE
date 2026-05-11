// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "CrossHairWidget.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UCrossHairWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UProgressBar* HealthBar;

	void SetPorcent(float value);
	
};
