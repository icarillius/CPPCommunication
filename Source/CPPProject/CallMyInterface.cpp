// Fill out your copyright notice in the Description page of Project Settings.


#include "CallMyInterface.h"

// Add default functionality here for any ICallMyInterface functions that are not pure virtual.

void ICallMyInterface::Interact(AActor* Interactor)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Interface is being called!"));
}
