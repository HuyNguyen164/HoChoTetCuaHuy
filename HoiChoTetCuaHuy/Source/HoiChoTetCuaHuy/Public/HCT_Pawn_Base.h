// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "HCT_Pawn_Base.generated.h"

class UInputMappingContext;
class UInputAction;
class UFloatingPawnMovement;

UCLASS()
class HOICHOTETCUAHUY_API AHCT_Pawn_Base : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHCT_Pawn_Base();

protected:
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
