// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
// adds the box component for the collision box
#include "Components/BoxComponent.h"
// adds the text render in the center of the box.
#include "Components/TextRenderComponent.h"
#include "CallMyInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerInterface.generated.h"

UCLASS()
class CPPPROJECT_API ATriggerInterface : public AActor, public ICallMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerInterface();

	UPROPERTY()
	UBoxComponent* BoxTrigger;
	//adds the text renderer for the writing
	UPROPERTY()
	UTextRenderComponent* renderText;
	//Function to allow for box collision.
	UFUNCTION()
	void TriggerVol(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
