// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"	
// adds the components for isms.
#include "Components/InstancedStaticMeshComponent.h"
#include "MyISMActor.generated.h"

UCLASS()
class CPPPROJECT_API AMyISMActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyISMActor();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//here we create a variable from the UISMC and set this to a pointer, 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Instancing")
	UInstancedStaticMeshComponent* ISMComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
