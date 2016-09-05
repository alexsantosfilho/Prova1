// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyActor2.h"
#include "Objetob.h"
#include "MyCharacter.h"
#include "ProjectActor.h"
#include "Teste.h"



// Sets default values
AMyActor2::AMyActor2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;
	//CollisionComp->OnComponentHit.AddDynamic(this, &AMyActor::OnHit);
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);
	CountdownTime = 4.0f;
	//CountupTimer = 2.0f;

}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	//GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AMyActor2::TimerManager, 4.0f, true);



}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	FVector LocalizacaoAtual = GetActorLocation();
	CountdownTime -= 1.0f;
	RunningTime3 += DeltaTime;
	float ObjetobTime = RunningTime3;
	RunningTime4 += DeltaTime;
	float ObjetobTime2 = RunningTime4;
	RunningTime5 += DeltaTime;
	float ObjetobTime5 = RunningTime5;

	if (ObjetobTime > 3.0f) {
		FActorSpawnParameters SpawnParameters;
		UWorld* World = GetWorld();
		if (World != nullptr) {
			FRotator Rotation = MeshComp->GetComponentRotation();
			AObjetob* Proj = World->SpawnActor<AObjetob>
				(GetActorLocation(), Rotation,
					SpawnParameters);
			if (Proj != nullptr) {

				RunningTime3 = 0.0f;
			}

		}

	}


	if (ObjetobTime2 > 3.5f) {
		float DeltaWidth = (FMath::Sin(RunningTime4 + DeltaTime) - FMath::Sin(RunningTime4));
		LocalizacaoAtual.Y += DeltaWidth * 150.0f;
		RunningTime4 += DeltaTime;
		SetActorLocation(LocalizacaoAtual);
		RunningTime4 = 0.0f;
		//Destroy();

	}

	//if (ObjetobTime5 > 3.0f) {
	//float DeltaWidth = (FMath::Sin(RunningTime5 + DeltaTime) - FMath::Sin(RunningTime5));
	//LocalizacaoAtual.X += DeltaWidth * 150.0f;
	//RunningTime5 += DeltaTime;
	//SetActorLocation(LocalizacaoAtual);
	//RunningTime5 = 0.0f;

	//Destroy();


	//	}

}

//else if (LocalizacaoAtual.X != LocalizacaoAtual.Y) {
//float DeltaHeight = (FMath::Sin(RunningTime - DeltaTime) - FMath::Sin(RunningTime));
//LocalizacaoAtual.X += DeltaHeight * 150.0f;
//RunningTime += DeltaTime;
//SetActorLocation(LocalizacaoAtual);
//}

//}


void AMyActor2::TimerManager() {
	CountdownTime -= 1.0f;
	if (CountdownTime <= 0.0f) {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		UE_LOG(LogTemp, Warning, TEXT(" TIME saida"));
		//Destroy();
	}
}


//void AMyActor2::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	//if (OtherActor && (OtherActor != this) && OtherComp)
	//{
	//OtherComp->AddImpulseAtLocation(AMyActor->Velocity * 100.0f, Hit.ImpactPoint);
	//}
//}


void AMyActor2::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	
	if (OtherActor->IsA(AProjectActor::StaticClass())) {

		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Destrui o bosss"));
	}
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetColetavel(MyCharacter->GetColetavel() - DamageAmount);
		MyCharacter->OnDeath();
		UE_LOG(LogTemp, Warning, TEXT("Coletavel = %d"), MyCharacter->GetColetavel());

	}
	
}