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
	//��UMG��ͼ�ؼ�
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UImage* IndicatorIcon;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0, ClampMax = 1))
		float LongAxisPercent = 0.7f;//��Բ����ռ��Ļ��Ȱٷֱ�
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0, ClampMax = 1))
		float MinorAixsPercent = 0.7f;//��Բ����ռ��Ļ�߶Ȱٷֱ�

	FVector2D ScreenPos;

	FTransform CameraTransform;
	
protected:
	void CalculateIndicatorScreenPos(FVector destination);

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
