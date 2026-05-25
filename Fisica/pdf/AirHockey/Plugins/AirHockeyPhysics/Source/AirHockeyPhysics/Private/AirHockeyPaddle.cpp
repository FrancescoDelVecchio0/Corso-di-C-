#include "AirHockeyPaddle.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AAirHockeyPaddle::AAirHockeyPaddle()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));

	CapsuleComponent->SetSimulatePhysics(true);

	CapsuleComponent->SetNotifyRigidBodyCollision(true);
	CapsuleComponent->SetGenerateOverlapEvents(true);
	CapsuleComponent->SetCapsuleSize(75.f, 150.f, false);

	RootComponent = CapsuleComponent;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMesh;
		FConstructorStatics()
			: CylinderMesh(TEXT("/Engine/BasicShapes/Cylinder")) { }
	};

	static FConstructorStatics ConstructorStatics;

	StaticMeshComponent->SetStaticMesh(ConstructorStatics.CylinderMesh.Object);
	StaticMeshComponent->SetRelativeScale3D(FVector(1.5f, 1.5f, 0.25f));
	
	StaticMeshComponent->SetNotifyRigidBodyCollision(false);
	StaticMeshComponent->SetGenerateOverlapEvents(false);

	StaticMeshComponent->SetupAttachment(CapsuleComponent);

	SpringArmComponent = CreateOptionalDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	if (SpringArmComponent)
	{
		SpringArmComponent->TargetArmLength = 750.f;
		SpringArmComponent->SocketOffset = FVector(0.f, 0.f, 300.f);
		SpringArmComponent->bDoCollisionTest = false;
		SpringArmComponent->bInheritPitch = false;
		SpringArmComponent->bInheritYaw = false;
		SpringArmComponent->bInheritRoll = false;
		SpringArmComponent->bEnableCameraRotationLag = false;

		SpringArmComponent->SetupAttachment(CapsuleComponent);
	}

	CameraComponent = CreateOptionalDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	if (CameraComponent)
	{
		CameraComponent->SetupAttachment(SpringArmComponent);
	}
}

void AAirHockeyPaddle::BeginPlay()
{
	Super::BeginPlay();
}

void AAirHockeyPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAirHockeyPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}