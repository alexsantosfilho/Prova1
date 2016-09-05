#pragma once

#include "GameFramework/Actor.h"
#include "Canh.generated.h"

UCLASS()
class MYPROJECT_API ACanh : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACanh();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


private:
	UPROPERTY(EditAnywhere)
	UShapeComponent* Root;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = Tick)
		float RunningTime;

};