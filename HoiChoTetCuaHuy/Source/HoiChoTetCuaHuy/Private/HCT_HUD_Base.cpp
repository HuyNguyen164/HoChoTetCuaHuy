// Fill out your copyright notice in the Description page of Project Settings.


#include "HoiChoTetCuaHuy/Public/HCT_HUD_Base.h"

#include "HoiChoTetCuaHuy/HoiChoTetCuaHuy.h"
#include "Blueprint/UserWidget.h"

AHCT_HUD_Base::AHCT_HUD_Base()
{
}

void AHCT_HUD_Base::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogHoiChoTetCuaHuy, Warning, TEXT("Bat dau xai HUD HoiChoTet"));
	
	if (TitleGameWidgetClass)
	{
		TitleGameWidget = CreateWidget<UUserWidget>(
			GetWorld(),
			TitleGameWidgetClass
		);

		if (TitleGameWidget)
		{
			TitleGameWidget->AddToViewport();
		}
	}
}
