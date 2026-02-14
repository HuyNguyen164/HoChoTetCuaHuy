#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"

#include "HCT_Pawn_Base.generated.h"

class UCapsuleComponent;
class UFloatingPawnMovement;
class UInputAction;
class UEnhancedInputComponent;

UCLASS()
class HOICHOTETCUAHUY_API AHCT_Pawn_Base : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHCT_Pawn_Base();

protected:
	virtual void BeginPlay() override;
	
	// Override this function to bind input actions and axes
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	// Input function for movement using Enhanced Input System
	void Move(const FInputActionValue& Value);
	
	// Component: Capsule Collider
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UCapsuleComponent* Capsule;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* MoveAction;
	
	UPROPERTY(VisibleAnywhere)
	UFloatingPawnMovement* FloatingMovement;
};
