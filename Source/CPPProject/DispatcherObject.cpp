// Fill out your copyright notice in the Description page of Project Settings.
#include "DispatcherObject.h"

// Sets default values
ADispatcherObject::ADispatcherObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Sends the signal that this object can be interacted with. 
	UpdateCollision.AddUniqueDynamic(this, &ADispatcherObject::TriggerInteract);
}

void ADispatcherObject::TriggerInteract()
{
	// Thing that happens IF message is recieved. 
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Delegate has been sent"));
	}
}


// Called when the game starts or when spawned
void ADispatcherObject::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADispatcherObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

