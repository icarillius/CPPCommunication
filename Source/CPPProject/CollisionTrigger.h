// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
// adds the box component for the collision box
#include "Components/BoxComponent.h"
// adds the text render in the center of the box.
#include "Components/TextRenderComponent.h"

#include "DispatcherObject.h"
#include "GameFramework/Actor.h"
#include "CollisionTrigger.generated.h"



//calls the delegate
UCLASS()
class CPPPROJECT_API ACollisionTrigger : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACollisionTrigger();
	//adds the box trigger for the collider.
	UPROPERTY()
	UBoxComponent* BoxTrigger;
	//adds the text renderer for the writing
	UPROPERTY()
	UTextRenderComponent* renderText;
	//Function to allow for box collision.
	UFUNCTION()
	void Trigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	//Stores the dispatcher, so this can be added in PIE/Editor
	UPROPERTY(EditAnywhere)
	ADispatcherObject* DispatcherObj;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
