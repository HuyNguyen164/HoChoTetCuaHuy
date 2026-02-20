// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HCT_Button_Base.h"
#include "HCT_Button_Explosion.generated.h"

class UNiagaraSystem;

UCLASS()
class HOICHOTETCUAHUY_API AHCT_Button_Explosion : public AHCT_Button_Base
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHCT_Button_Explosion();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HoiChoTet|Explosion")
	TObjectPtr<UNiagaraSystem> ExplosionEffect;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
