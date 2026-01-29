// Fill out your copyright notice in the Description page of Project Settings.


#include "HoiChoTetCuaHuy/Public/HCT_PlayerController_Base.h"

#include "HoiChoTetCuaHuy/HoiChoTetCuaHuy.h"

AHCT_PlayerController_Base::AHCT_PlayerController_Base()
{
}

void AHCT_PlayerController_Base::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogHoiChoTetCuaHuy, Warning, TEXT("Bat dau xai PlayerController HoiChoTet"));
}
