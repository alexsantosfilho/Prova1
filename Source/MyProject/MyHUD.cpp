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
		Texture(TEXT("Texture2D'/Game/Red_Textureee.Red_Textureee'"));
	if (Texture.Succeeded()) {
		MyTexture = Texture.Object;
	}
	static ConstructorHelpers::FObjectFinder<UTexture2D>
		Texture2(TEXT("Texture2D'/Game/Blue_Textureee.Blue_Textureee'"));
	if (Texture2.Succeeded()) {
		MyTexture2 = Texture2.Object;
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

	FString LColetavelString = FString::Printf(TEXT("Coletavel: %d"),
		MyCharacter->GetLColetavel());
	DrawText(LColetavelString, FColor::Blue, 50, 140, HUDFont);

	



	//DrawTextureSimple(MyTexture, 50, 50, 1.0f, false);

	DrawTexture(MyTexture, 200, 50, MyCharacter->GetColetavel() * 35,
		MyTexture->GetSizeY(), 0, 0, MyCharacter->GetColetavel() * 4,
		MyTexture->GetSizeY(), FLinearColor::White,
		EBlendMode::BLEND_Translucent, 1.0f, false, 0.0f,
		FVector2D::ZeroVector);



	DrawTexture(MyTexture2, 200, 140, MyCharacter->GetLColetavel() * 35,
		MyTexture2->GetSizeY(), 0, 0, MyCharacter->GetLColetavel() * 4,
		MyTexture2->GetSizeY(), FLinearColor::White,
		EBlendMode::BLEND_Translucent, 1.0f, false, 0.0f,
		FVector2D::ZeroVector);
}





