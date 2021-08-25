// Fill out your copyright notice in the Description page of Project Settings.


#include "IndicatorWidget.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "GameFramework/Character.h"
#include "Components/CanvasPanelSlot.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

void UIndicatorWidget::CalculateIndicatorScreenPos(FVector destination)
{
	auto playController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	ACharacter* myCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (playController == nullptr || myCharacter == nullptr)
	{
		return;
	}
	CameraTransform.SetLocation(UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation());
	CameraTransform.SetRotation(UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraRotation().Quaternion());

	auto localDestination = CameraTransform.InverseTransformPositionNoScale(destination);

	FVector2D destinationDir = FVector2D(localDestination.Y, localDestination.Z);
	destinationDir.Normalize();
	int32 viewPortX, viewPortY;
	playController->GetViewportSize(viewPortX, viewPortY);

	float k = destinationDir.Y / destinationDir.X;

	float designSizeX = viewPortX / UWidgetLayoutLibrary::GetViewportScale(this);
	float designSizeY = viewPortY / UWidgetLayoutLibrary::GetViewportScale(this);
	
	//在UI空间下x轴往右，y轴往下
	//椭圆公式 y^2/a^2 + x^2/b^2 = 1
	float a = LongAxisPercent * designSizeX / 2;
	float b = MinorAixsPercent * designSizeY / 2;

	//求解交点
	float x = UKismetMathLibrary::SignOfFloat(destinationDir.X) * UKismetMathLibrary::Sqrt((a * a * b * b) / (b * b + a * a * k * k));
	float y = k * x;
	ScreenPos.X = x;

	ScreenPos.Y = -1 * y;

	FVector2D ScreenPosition;
	if (UWidgetLayoutLibrary::ProjectWorldLocationToWidgetPosition(playController, destination, ScreenPosition, false))
	{
		//算出来的ScreenPos原点在左上角
		auto ScreenPosX = ScreenPosition.X;
		auto ScreenPosY = ScreenPosition.Y;
		
		if (ScreenPosX < designSizeX && ScreenPosY < designSizeY && ScreenPosX > 0 && ScreenPosY > 0)
		{
			ScreenPosX -= designSizeX / 2;
			ScreenPosY -= designSizeY / 2;
			if (((ScreenPosX * ScreenPosX) / (a * a) + (ScreenPosY * ScreenPosY) / (b * b)) < 1)
			{
				ScreenPos.X = ScreenPosX;
				ScreenPos.Y = ScreenPosY;
			}
		}
	}
}

void UIndicatorWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	//测试用的位置，实际使用时传入需要的位置
	CalculateIndicatorScreenPos(FVector::UpVector * 200);
	auto canvasSlot = Cast<UCanvasPanelSlot>(Slot);
	if (canvasSlot) {
		canvasSlot->SetPosition(ScreenPos);
	}
}
