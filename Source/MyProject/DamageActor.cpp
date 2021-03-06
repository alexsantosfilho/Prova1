// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "DamageActor.h"
#include "MyCharacter.h"


// Sets default values
ADamageActor::ADamageActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent >(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &ADamageActor::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoColision");
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void ADamageActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamageActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ADamageActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) { 

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetColetavel(MyCharacter->GetColetavel() - DamageAmount);
		MyCharacter->OnDeath();
		UE_LOG(LogTemp, Warning, TEXT("Coletavel = %d"), MyCharacter->GetColetavel());
		Destroy();
	}

}

