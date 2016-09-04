// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Canh.h"
#include "Shoot.h"



// Sets default values
ACanh::ACanh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->SetCollisionProfileName("BlockAllDynamic");
	RootComponent = Root;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/Shape_Cylinder.Shape_Cylinder'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/M_Metal_Gold.M_Metal_Gold'"));
	if (Material.Succeeded()) {
		MeshComp->SetMaterial(0, Material.Object);
	}
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(1.5f, 0.7f, 0.7f));
	MeshComp->AttachTo(RootComponent);
}



// Called when the game starts or when spawned
void ACanh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACanh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
	float ShootTime = 1.0f * RunningTime;
	if (ShootTime > 2.0f) {
		FActorSpawnParameters SpawnParameters;
		UWorld* World = GetWorld();
		if (World != nullptr) {
			FRotator Rotation = MeshComp->GetComponentRotation();
			AShoot* Proj = World->SpawnActor<AShoot>
				(GetActorLocation(), Rotation,
					SpawnParameters);
			if (Proj != nullptr) {

				RunningTime = 0.0f;
			}

		}

	}
}