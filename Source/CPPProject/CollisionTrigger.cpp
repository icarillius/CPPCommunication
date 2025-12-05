// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

#include "CollisionTrigger.h"
//Adds Dispatcher Object so can can send the signal
#include "DispatcherObject.h"

// Sets default values
ACollisionTrigger::ACollisionTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Creates the collision Box
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Volume"));
	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &ACollisionTrigger::Trigger);
	BoxTrigger->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = BoxTrigger;
	

	//Creates the text renderer and centers it.
	renderText = CreateDefaultSubobject<UTextRenderComponent>("TextComponent");
	renderText->SetTextRenderColor(FColor::Green);
	renderText->SetText(FText::FromString("This is a Delegate Trigger Box"));
	renderText->SetupAttachment(GetRootComponent());
	renderText->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));
	renderText->SetHorizontalAlignment(EHTA_Center);

	
}

//When Collision Trigger happens, debug menu pops.
void ACollisionTrigger::Trigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Type Safe System Checks if can be triggered.
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Triggered"));

	//Checks if Object dispatcher Object Exists.
	if (DispatcherObj)
	{
		//Fires if true.
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Is True"));
		//Sends Broadcast                                               
		DispatcherObj->UpdateCollision.Broadcast();
		}
	else
	{
		// if a nullptr on the dispatcherobj will return. 
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Nullptr Dispatcherobj"));
	}
}



// Called when the game starts or when spawned
void ACollisionTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollisionTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

