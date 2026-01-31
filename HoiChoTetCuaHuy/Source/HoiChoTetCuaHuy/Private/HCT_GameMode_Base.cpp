// Fill out your copyright notice in the Description page of Project Settings.


#include "HoiChoTetCuaHuy/Public/HCT_GameMode_Base.h"

#include "HCT_HUD_Base.h"
#include "HCT_PlayerController_Base.h"
#include "HoiChoTetCuaHuy/HoiChoTetCuaHuy.h"

AHCT_GameMode_Base::AHCT_GameMode_Base()
{
	PlayerControllerClass = AHCT_PlayerController_Base::StaticClass();
	DefaultPawnClass = AHCT_PlayerController_Base::StaticClass();
	HUDClass = AHCT_HUD_Base::StaticClass();
}

void AHCT_GameMode_Base::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogHoiChoTetCuaHuy, Warning, TEXT("Bat dau xai GameMode HoiChoTet"));
}
