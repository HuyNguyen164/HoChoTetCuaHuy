#include "HCT_Button_Base.h"
#include "Components/BoxComponent.h"


// Sets default values
AHCT_Button_Base::AHCT_Button_Base()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create Root Scene Component
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot); // or RootComponent = SceneRoot;
	
	// Create Collision
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionComponent->SetupAttachment(RootComponent);
	CollisionComponent->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CollisionComponent->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AHCT_Button_Base::BeginPlay()
{
	Super::BeginPlay();
	
	// Bind overlap events
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AHCT_Button_Base::OnOverlapBegin);
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &AHCT_Button_Base::OnOverlapEnd);
}

// Called every frame
void AHCT_Button_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AHCT_Button_Base::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		StartOverlap.Broadcast(OtherActor);
	}
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AHCT_Button_Base::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor != this)
	{
		EndOverlap.Broadcast(OtherActor);
	}
}