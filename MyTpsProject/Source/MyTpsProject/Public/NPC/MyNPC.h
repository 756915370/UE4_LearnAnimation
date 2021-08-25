// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Actor.h"
#include "MyNPC.generated.h"

UCLASS()
class MYTPSPROJECT_API AMyNPC : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyNPC();

	//UPROPERTY(VisibleAnywhere, Category = "UI")
	//	UWidgetComponent* NPCWidgetComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
