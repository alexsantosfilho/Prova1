// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyActorInimigot.h"


// Sets default values
AMyActorInimigot::AMyActorInimigot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	MeshComp->AttachTo(RootComponent);


	Particle = CreateDefaultSubobject<UParticleSystemComponent>
		(TEXT("Particle"));
	Particle->bAutoActivate = true;
	static ConstructorHelpers::FObjectFinder<UParticleSystem>
		ParticleSystem(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));

	if (ParticleSystem.Succeeded()) {
		Particle->SetTemplate(ParticleSystem.Object);

	}
	Particle->SetupAttachment(RootComponent);

	ProjecttileMovement = CreateDefaultSubobject <UProjectileMovementComponent>(TEXT("ProjecttileMovement"));
	ProjecttileMovement->UpdatedComponent = Root;
	ProjecttileMovement->InitialSpeed = 1500.0f;
	ProjecttileMovement->MaxSpeed = 1500.0f;


	InitialLifeSpan = 5.0f;

}

// Called when the game starts or when spawned
void AMyActorInimigot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorInimigot::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

