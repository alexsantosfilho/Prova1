// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyCharacter2.h"


// Sets default values
AMyCharacter2::AMyCharacter2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter2::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

