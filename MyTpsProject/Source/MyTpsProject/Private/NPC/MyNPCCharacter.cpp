// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/MyNPCCharacter.h"
#include "Components/WidgetComponent.h"

// Sets default values
AMyNPCCharacter::AMyNPCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NPCWidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("NPCWidgetComponent"));

	static ConstructorHelpers::FClassFinder<UUserWidget> HeadWidget(TEXT("WidgetBlueprint'/Game/Blueprint/UserWidgets/WBP_NPCHeadInfo.WBP_NPCHeadInfo_C'"));
	NPCWidgetComp->SetWidgetClass(HeadWidget.Class);
	NPCWidgetComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	NPCWidgetComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyNPCCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyNPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyNPCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

