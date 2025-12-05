// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DispatcherObject.generated.h"

//creates the delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FupdateCollision);

UCLASS()
class CPPPROJECT_API ADispatcherObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADispatcherObject();

	
	//Sets Delegate to this Object on Collision.
	FupdateCollision UpdateCollision;

private:
	//Private Function of what gets trigged based of the delegate.
	UFUNCTION()
	void TriggerInteract();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
