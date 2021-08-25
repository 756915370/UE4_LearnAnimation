// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/MyNPC.h"

// Sets default values
AMyNPC::AMyNPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//NPCWidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("NPCWidgetComponent"));
	
}

// Called when the game starts or when spawned
void AMyNPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

