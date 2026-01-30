// Fill out your copyright notice in the Description page of Project Settings.


#include "HCT_Pawn_Base.h"
// #include "EnhancedInputSubsystems.h"
#include "HoiChoTetCuaHuy/HoiChoTetCuaHuy.h"


// Sets default values
AHCT_Pawn_Base::AHCT_Pawn_Base()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Cho phep dieu khien bang Player 0
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AHCT_Pawn_Base::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogHoiChoTetCuaHuy, Warning, TEXT("Bat dau xai Pawn HoiChoTet"));
	
//	// Add Input Mapping Context
//	APlayerController* PC = Cast<APlayerController>(GetController());
//	if (!PC) return;

//	ULocalPlayer* LocalPlayer = PC->GetLocalPlayer();
//	if (!LocalPlayer) return;

//	UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
//		LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

//	if (InputSubsystem && IMC_Base)
//	{
//		InputSubsystem->AddMappingContext(IMC_Base, 0);
//	}
}

// Called every frame
void AHCT_Pawn_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AHCT_Pawn_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

