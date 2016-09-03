// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyActor.h"
#include "MyCharacter.h"
#include "ProjectActor.h"



// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;
	//CollisionComp->OnComponentHit.AddDynamic(this, &AMyActor::OnHit);
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LocalizacaoAtual = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	LocalizacaoAtual.Y += DeltaHeight * 400.0f;
	RunningTime += DeltaTime;
	SetActorLocation(LocalizacaoAtual);


}

void AMyActor::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	//if (OtherActor && (OtherActor != this) && OtherComp)
	//{
		//OtherComp->AddImpulseAtLocation(AMyActor->Velocity * 100.0f, Hit.ImpactPoint);
	//}
}



void AMyActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetColetavel(MyCharacter->GetColetavel() - DamageAmount);
		MyCharacter->OnDeath();
		UE_LOG(LogTemp, Warning, TEXT("Coletavel = %d"), MyCharacter->GetColetavel());
		Destroy();


	}
}


