// Fill out your copyright notice in the Description page of Project Settings.


#include "HCT_PlayerController_Base.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "HoiChoTetCuaHuy/HoiChoTetCuaHuy.h"

AHCT_PlayerController_Base::AHCT_PlayerController_Base()
{
}

void AHCT_PlayerController_Base::BeginPlay()
{
	Super::BeginPlay();
	
	//Debug
	UE_LOG(LogHoiChoTetCuaHuy, Warning, TEXT("IMC added"));
}

void AHCT_PlayerController_Base::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->ClearAllMappings();

			if (IMC_Base)
			{
				Subsystem->AddMappingContext(IMC_Base, 0);
				UE_LOG(LogHoiChoTetCuaHuy, Warning, TEXT("IMC added (OnPossess)"));
			}
		}
	}
}

void AHCT_PlayerController_Base::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EIC =
		Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (IA_LookAround)
		{
			EIC->BindAction(
				IA_LookAround,
				ETriggerEvent::Triggered,
				this,
				&AHCT_PlayerController_Base::LookAround
			);
		}
	}
}

void AHCT_PlayerController_Base::LookAround(const FInputActionValue& Value)
  {
  	const FVector2D LookAxisValue = Value.Get<FVector2D>();	
  	
  	AddYawInput(LookAxisValue.X);
  	AddPitchInput(LookAxisValue.Y);
  }
