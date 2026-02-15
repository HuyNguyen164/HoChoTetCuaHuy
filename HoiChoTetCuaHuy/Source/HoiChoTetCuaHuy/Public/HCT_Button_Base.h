#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HCT_Button_Base.generated.h"

class UBoxComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSignatureKhiBatDauOverlap, AActor*, OverlappingActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSignatureKhiHetOverlap, AActor*, OverlappingActor);

UCLASS()
class HOICHOTETCUAHUY_API AHCT_Button_Base : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHCT_Button_Base();
	
	UPROPERTY(BlueprintAssignable, Category=HoiChoTet)
	FSignatureKhiBatDauOverlap StartOverlap;
	
	UPROPERTY(BlueprintAssignable, Category=HoiChoTet)
	FSignatureKhiHetOverlap EndOverlap;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* SceneRoot;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* CollisionComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
