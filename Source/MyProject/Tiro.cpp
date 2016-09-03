// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Tiro.h"


// Sets default values
ATiro::ATiro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATiro::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATiro::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

