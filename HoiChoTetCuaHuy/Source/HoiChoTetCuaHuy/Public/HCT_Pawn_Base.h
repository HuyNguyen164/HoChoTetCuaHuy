// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

//#include "GameplayTagContainer.h"
//#include "GameplayTagAssetInterface.h"

#include "HCT_Pawn_Base.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class HOICHOTETCUAHUY_API AHCT_Pawn_Base : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHCT_Pawn_Base();
	
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gameplay Tags")
//	FGameplayTagContainer GameplayTags;
//
//	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override
//	{
//		TagContainer = GameplayTags;
//	}

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
