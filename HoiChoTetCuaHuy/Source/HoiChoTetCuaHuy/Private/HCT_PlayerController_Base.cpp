// Fill out your copyright notice in the Description page of Project Settings.


#include "HoiChoTetCuaHuy/Public/HCT_PlayerController_Base.h"
#include "EnhancedInputSubsystems.h"
#include "HoiChoTetCuaHuy/HoiChoTetCuaHuy.h"

AHCT_PlayerController_Base::AHCT_PlayerController_Base()
{
}

void AHCT_PlayerController_Base::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogHoiChoTetCuaHuy, Warning, TEXT("Bat dau xai PlayerController HoiChoTet"));
	
	// Them Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (IMC_Base)
		{
			Subsystem->AddMappingContext(IMC_Base, 0);
		}
	}
	
	UE_LOG(LogHoiChoTetCuaHuy, Warning, TEXT("PlayerController da dung IMC_Base"));
}
