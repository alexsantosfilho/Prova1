// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMyHUD();

	UPROPERTY(EditAnywhere)
		UFont* HUDFont;
	UPROPERTY(EditAnywhere)
		UTexture2D* MyTexture;
	UPROPERTY(EditAnywhere)
		UTexture2D* MyTexture2;

	virtual void DrawHUD() override;
	
	
	
};
