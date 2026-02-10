// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "HCT_PlayerController_Base.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class HOICHOTETCUAHUY_API AHCT_PlayerController_Base : public APlayerController
{
	GENERATED_BODY()
	
	AHCT_PlayerController_Base();
	
protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void SetupInputComponent() override;
	
	// Input callback
	void LookAround(const FInputActionValue& Value);
	
	// Khai bao Input Mapping Context va Input Action
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* IMC_Base;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_LookAround;
};