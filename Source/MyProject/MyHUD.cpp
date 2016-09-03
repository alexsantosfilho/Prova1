// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyHUD.h"
#include "Engine/Font.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"

AMyHUD::AMyHUD() {
	static ConstructorHelpers::FObjectFinder<UFont>
		Font(TEXT("Font'/Engine/EngineFonts/RobotoDistanceField.RobotoDistanceField'"));
	if (Font.Succeeded()) {
		HUDFont = Font.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D>
		Texture(TEXT("Texture2D'/Game/StarterContent/Textures/Green_Textureee.Green_Textureee'"));
	if (Texture.Succeeded()) {
		MyTexture = Texture.Object;
	}
}

void AMyHUD::DrawHUD() {
	Super::DrawHUD();

	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX,
		Canvas->SizeY);

	AMyCharacter* MyCharacter = Cast<AMyCharacter>(
		UGameplayStatics::GetPlayerPawn(this, 0));

	FString ColetavelString = FString::Printf(TEXT("Vida: %d"),
		MyCharacter->GetColetavel());
	DrawText(ColetavelString, FColor::Red, 50, 50, HUDFont);

	//DrawTextureSimple(MyTexture, 200, 50, 1.0f, false);

	DrawTexture(MyTexture, 200, 50, MyCharacter->GetColetavel() * 35,
		MyTexture->GetSizeY(), 0, 0, MyCharacter->GetColetavel() * 4,
		MyTexture->GetSizeY(), FLinearColor::White,
		EBlendMode::BLEND_Translucent, 1.0f, false, 0.0f,
		FVector2D::ZeroVector);
}





