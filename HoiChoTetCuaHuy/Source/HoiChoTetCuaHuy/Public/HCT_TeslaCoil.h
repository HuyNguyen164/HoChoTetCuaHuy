#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "HCT_TeslaCoil.generated.h"

UCLASS()
class HOICHOTETCUAHUY_API AHCT_TeslaCoil : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHCT_TeslaCoil();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Components)
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=VFX)
	UNiagaraComponent* TeslaCoilEffect;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=VFX)
	UNiagaraComponent* BoundaryEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Collision)
	USphereComponent* DetectionSphere;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called when the actor is constructed, both in editor and at runtime
	virtual void OnConstruction(const FTransform& Transform) override;

	// Cached reference to the player pawn
	UPROPERTY(BlueprintReadOnly, Category=Player)
	APawn* CachedPlayerPawn;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
						AActor* OtherActor,
						UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex,
						bool bFromSweep,
						const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
					  AActor* OtherActor,
					  UPrimitiveComponent* OtherComp,
					  int32 OtherBodyIndex);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
