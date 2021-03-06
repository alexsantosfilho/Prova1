// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Teste.generated.h"

UCLASS()
class MYPROJECT_API ATeste : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeste();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	UPROPERTY(EditAnywhere)
		UShapeComponent* Root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere, Category = Tick)
		float RunningTime;
	UPROPERTY(EditAnywhere)
		float DamageAmount = 1;
	//UFUNCTION()
		//void OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
//			FVector NormalImpulse, const FHitResult& Hit);
	
		UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



	
};
