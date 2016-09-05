// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class MYPROJECT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	float velocidadeDeRotacao;
	
	
	void SetColetavel(int NewColetavel);
	int GetColetavel();

	void SetLColetavel(int NewLColetavel);
	int GetLColetavel();
	
	void OnDeath();

	void OnDeath1();



	void RotacionarEmZ(float eixoHorizontal);
	void RotacionarEmX(float eixoVertical);
	
	
private: 
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere)
		UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere)
	UArrowComponent* ArrowComp;
	UPROPERTY(EditAnywhere)

	int Coletavel = 3;
	int LColetavel = 0;


	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);





	void MoveForward(float value);
	void MoveRight(float Value);
	
	void StartRun();
	void StopRun();
	void DropProjectActor();
	void Turn(float Value);



	
};
