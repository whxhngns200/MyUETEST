// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyGamePlayInterface.h"
#include "MyItemChest.generated.h"

UCLASS()
class AMyItemChest : public AActor, public IMyGamePlayInterface
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere);
	float TartPitch;
	// Sets default values for this actor's properties
	AMyItemChest();

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void Interact_Implementation(APawn* InstigatorParam) override;

};
