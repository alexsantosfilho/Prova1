// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Teste.h"
#include "MyCharacter.h"
#include "ProjectActor.h"

// Sets default values
ATeste::ATeste()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &ATeste::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void ATeste::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeste::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector LocalizacaoAtual = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	LocalizacaoAtual.Y += DeltaHeight * 400.0f;
	RunningTime += DeltaTime;
	SetActorLocation(LocalizacaoAtual);


}

void ATeste::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetColetavel(MyCharacter->GetColetavel() - DamageAmount);
		MyCharacter->OnDeath();
		UE_LOG(LogTemp, Warning, TEXT("Coletavel = %d"), MyCharacter->GetColetavel());

	}
	if (OtherActor->IsA(AProjectActor::StaticClass())) {

		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Destruiuuukakoaksj"));
	}
}

//void ATeste::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	//if (OtherActor && (OtherActor != this) && OtherComp)
	//{
	//OtherComp->AddImpulseAtLocation(AMyActor->Velocity * 100.0f, Hit.ImpactPoint);
	//}
//}