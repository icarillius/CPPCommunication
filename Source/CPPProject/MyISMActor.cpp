// Fill out your copyright notice in the Description page of Project Settings.

//Adds the Uboject constructor helpers allows us to find objects using the objectfinder. 
#include "UObject/ConstructorHelpers.h"
#include "MyISMActor.h"

// Sets default values
AMyISMActor::AMyISMActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Here we create the mesh of the component, this is linked to the object which is currently opened up in the header so we can set this in the project.
	ISMComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ISMComponent"));
	ISMComponent->SetupAttachment(RootComponent);
	//Sets the object of the ISM here, we have used the cube from the engine defeaul library. 
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/EngineMeshes/Cube.Cube"));
	if (MeshAsset.Succeeded())
	{
		ISMComponent->SetStaticMesh(MeshAsset.Object);
	}
	// This allows the ism to be movable, as well as blocks collision on the object.
	ISMComponent->SetMobility(EComponentMobility::Movable);
	ISMComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);

}

// Called when the game starts or when spawned
void AMyISMActor::BeginPlay()
{
	Super::BeginPlay();
	//Here we developed a loop for 9 items, here it builds the object and then mvoes this on by 400 then builds the next object.
	for (int32 i = 0; i < 10; ++i)
	{
		FTransform InstanceTransform(FVector(i * 400.f, 0.f, 0.f));
		ISMComponent->AddInstance(InstanceTransform);
	}
}

// Called every frame
void AMyISMActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

