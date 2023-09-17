// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ASMagicProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;


UCLASS()
class MYUETEST_API AASMagicProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereCom;
	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* MovementCom;
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* EffectCom;
	// Sets default values for this actor's properties
	AASMagicProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
