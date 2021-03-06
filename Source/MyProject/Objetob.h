// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Objetob.generated.h"

UCLASS()
class MYPROJECT_API AObjetob : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjetob();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:

	UPROPERTY(EditAnywhere)
		UBoxComponent* Root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* Particle;
	UPROPERTY(EditAnywhere)
		UProjectileMovementComponent* ProjectileMovement;

	float RunningTime;
	UPROPERTY(VisibleAnywhere, Category = Tick)

	float DefaultZ;
	float DamageAmount = 3.0f;
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, Category = Tick)
		float RunningTime3;



};
	

