#include "AirHockeyDisk.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

AAirHockeyDisk::AAirHockeyDisk()
{
	PrimaryActorTick.bCanEverTick = false;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));

	CapsuleComponent->SetSimulatePhysics(true);

	CapsuleComponent->SetNotifyRigidBodyCollision(true);
	CapsuleComponent->SetGenerateOverlapEvents(true);
	CapsuleComponent->SetCapsuleSize(50.f, 100.f, false);

	RootComponent = CapsuleComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->PrimaryComponentTick.TickGroup = TG_PrePhysics;

	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UStaticMesh> CyclinderMesh;
		FConstructorStatics()
			: CyclinderMesh(TEXT("/Engine/BasicShapes/Cylinder")) {
		}
	};

	static FConstructorStatics ConstructorStatics;
	MeshComponent->SetStaticMesh(ConstructorStatics.CyclinderMesh.Object);
	MeshComponent->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.1f));

	MeshComponent->SetNotifyRigidBodyCollision(false);
	MeshComponent->SetGenerateOverlapEvents(false);

	MeshComponent->SetupAttachment(CapsuleComponent);
}