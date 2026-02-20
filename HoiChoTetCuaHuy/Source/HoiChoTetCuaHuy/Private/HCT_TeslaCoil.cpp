#include "HCT_TeslaCoil.h"

float BoundaryRadius = 350.f;

// Sets default values
AHCT_TeslaCoil::AHCT_TeslaCoil()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create root scene component
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	// Create a Niagara component for Tesla coil effect and attach to root
	TeslaCoilEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Tesla Coil Niagara Component"));
	TeslaCoilEffect->SetupAttachment(SceneRoot);

	// Create a Niagara component for area effect and attach to root
	BoundaryEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Boundary Effect Niagara Component"));
	BoundaryEffect->SetupAttachment(SceneRoot);

	// Initialize cached pawn pointer
	CachedPlayerPawn = nullptr;
	
	// Create a sphere component for detecting player proximity and attach to root
	DetectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionSphere"));
	DetectionSphere->SetupAttachment(SceneRoot);
	DetectionSphere->SetSphereRadius(BoundaryRadius);

	DetectionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	DetectionSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	DetectionSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
	// Bind overlap events
	DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &AHCT_TeslaCoil::OnOverlapBegin);
	DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &AHCT_TeslaCoil::OnOverlapEnd);
	
	// Deactivate the Tesla Coil when Begin PLays
	TeslaCoilEffect->SetAutoActivate(false);
}

// Called when the actor is constructed, both in editor and at runtime
void AHCT_TeslaCoil::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (BoundaryEffect != nullptr)
	{
		BoundaryEffect->SetFloatParameter(FName("Radius"), BoundaryRadius);
		BoundaryEffect->SetFloatParameter(FName("Height"), 600.f);
		BoundaryEffect->SetColorParameter(FName("Color"), FLinearColor::FromSRGBColor(FColor(0, 255, 0)));
	}
}

// Called when the game starts or when spawned
void AHCT_TeslaCoil::BeginPlay()
{
	Super::BeginPlay();
	
	// Cache the player's pawn
	if (const APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		CachedPlayerPawn = PlayerController->GetPawn();
	}
}

// Overlap event handlers
void AHCT_TeslaCoil::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor == CachedPlayerPawn)
	{
		TeslaCoilEffect->Activate();
	}
}

void AHCT_TeslaCoil::OnOverlapEnd(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherActor == CachedPlayerPawn)
	{
		TeslaCoilEffect->Deactivate();
	}
}

// Called every frame
void AHCT_TeslaCoil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (TeslaCoilEffect->IsActive() && CachedPlayerPawn)
	{
		TeslaCoilEffect->SetVariablePosition(
			FName("PositionTarget"),
			CachedPlayerPawn->GetActorLocation());
	}
}


