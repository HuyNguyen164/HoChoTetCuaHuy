// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HCT_PlayerController_Base.generated.h"

/**
 * 
 */
UCLASS()
class HOICHOTETCUAHUY_API AHCT_PlayerController_Base : public APlayerController
{
	GENERATED_BODY()
	
	AHCT_PlayerController_Base();
	
public:
	virtual void BeginPlay() override;
};
