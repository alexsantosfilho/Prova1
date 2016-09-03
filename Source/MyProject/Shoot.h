// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Shoot.generated.h"

UCLASS()
class MYPROJECT_API AShoot : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShoot();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

private:

	UBoxComponent* Root;
	UStaticMeshComponent* MeshComp;
	UParticleSystemComponent* Particle;
	UProjectileMovementComponent* ProjectileMovement;

	float DefaultZ;
	float DamageAmount = 1.0f;
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, Category = Tick)
		float RunningTime;



};