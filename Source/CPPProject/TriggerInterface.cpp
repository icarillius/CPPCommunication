// Fill out your copyright notice in the Description page of Project Settings.
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

#include "TriggerInterface.h"

// Sets default values
ATriggerInterface::ATriggerInterface()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Creates the collision Box
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Volume"));
	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &ATriggerInterface::TriggerVol);
	BoxTrigger->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = BoxTrigger;


	//Creates the text renderer and centers it.
	renderText = CreateDefaultSubobject<UTextRenderComponent>("TextComponent");
	renderText->SetTextRenderColor(FColor::Green);
	renderText->SetText(FText::FromString("This is a Interface Trigger Box"));
	renderText->SetupAttachment(GetRootComponent());
	renderText->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));
	renderText->SetHorizontalAlignment(EHTA_Center);
}

void ATriggerInterface::TriggerVol(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ICallMyInterface::Interact(this);
}

// Called when the game starts or when spawned
void ATriggerInterface::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATriggerInterface::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

