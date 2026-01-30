// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HCT_HUD_Base.generated.h"

/**
 * 
 */
UCLASS()
class HOICHOTETCUAHUY_API AHCT_HUD_Base : public AHUD
{
	GENERATED_BODY()
	
	AHCT_HUD_Base();
	
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> TitleGameWidgetClass;

	UPROPERTY()
	UUserWidget* TitleGameWidget;
};
