// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInteractionComponent.h"
#include "MyGamePlayInterface.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UMyInteractionComponent::UMyInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UMyInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	AActor* MyOwner = GetOwner();

	FVector ELocation;
	FRotator ERotator;
	MyOwner->GetActorEyesViewPoint(ELocation, ERotator);

	FVector End = ELocation + (ERotator.Vector()*1000);
	FHitResult HitR;
	TArray<FHitResult> THit;
	FCollisionShape Shape;
	float Radios = 50.0f;
	Shape.SetSphere(Radios);
	GetWorld()->SweepMultiByObjectType(THit, ELocation, End, FQuat::Identity, ObjectQueryParams, Shape);
	//GetWorld()->LineTraceSingleByObjectType(HitR, ELocation, End, ObjectQueryParams);
	for (FHitResult Hit : THit) {
		AActor* HitActor = Hit.GetActor();
		if (HitActor) {
			if (HitActor->Implements<UMyGamePlayInterface>()) {
				APawn* apawn = Cast<APawn>(MyOwner);
				IMyGamePlayInterface::Execute_Interact(HitActor, apawn);
				break;
			}
		}
		DrawDebugSphere(GetWorld(), Hit.ImpactPoint, Radios, 32, FColor::Red, false, 2, 0, 2);
	}
	DrawDebugLine(GetWorld(), ELocation, End, FColor::Red, false, 2, 0, 2);
}

// Called when the game starts
void UMyInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

