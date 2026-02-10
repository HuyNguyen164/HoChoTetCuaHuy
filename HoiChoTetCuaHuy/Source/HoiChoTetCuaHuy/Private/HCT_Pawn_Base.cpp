// Fill out your copyright notice in the Description page of Project Settings.


#include "HCT_Pawn_Base.h"

#include "HoiChoTetCuaHuy/HoiChoTetCuaHuy.h"


// Sets default values
AHCT_Pawn_Base::AHCT_Pawn_Base()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Root
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	
	// Cho phep xoay theo huong camera
	bUseControllerRotationYaw = true;
	
	// Cho phep dieu khien bang Player 0
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void AHCT_Pawn_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Called when the game starts or when spawned
void AHCT_Pawn_Base::BeginPlay()
{
	Super::BeginPlay();
	
	//Debug
	UE_LOG(LogHoiChoTetCuaHuy, Warning,
	TEXT("Pawn BeginPlay | Controller = %s"),
	Controller ? *Controller->GetName() : TEXT("NULL"));
	
	UE_LOG(LogHoiChoTetCuaHuy, Warning, TEXT("Bat dau xai Pawn HoiChoTet"));
}

// Called every frame
void AHCT_Pawn_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
