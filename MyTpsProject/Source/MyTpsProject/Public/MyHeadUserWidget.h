// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyHeadUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYTPSPROJECT_API UMyHeadUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	FVector2D GetWidgetGeometrySize(UWidget* widget)
	{
		auto cacheGeometry = widget->GetCachedGeometry();
		return cacheGeometry.GetAbsolutePosition();
	}
};
