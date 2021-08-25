// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "IndicatorWidget.generated.h"


/**
 * 
 */
UCLASS()
class MYTPSPROJECT_API UIndicatorWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	//绑定UMG蓝图控件
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UImage* IndicatorIcon;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0, ClampMax = 1))
		float LongAxisPercent = 0.7f;//椭圆长轴占屏幕宽度百分比
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0, ClampMax = 1))
		float MinorAixsPercent = 0.7f;//椭圆短轴占屏幕高度百分比

	FVector2D ScreenPos;

	FTransform CameraTransform;
	
protected:
	void CalculateIndicatorScreenPos(FVector destination);

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
