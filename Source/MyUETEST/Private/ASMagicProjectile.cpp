// Fill out your copyright notice in the Description page of Project Settings.

#include "ASMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "particles/ParticleSystemComponent.h"

// Sets default values
AASMagicProjectile::AASMagicProjectile()
{
	SphereCom = CreateDefaultSubobject<USphereComponent>("SphereCom");
	RootComponent = SphereCom;
	//SphereCom->SetCollisionObjectType(ECC_WorldDynamic);
	SphereCom->SetCollisionProfileName("Projectile");

	EffectCom = CreateDefaultSubobject<UParticleSystemComponent>("EffectCom");
	EffectCom->SetupAttachment(SphereCom);
	MovementCom = CreateDefaultSubobject<UProjectileMovementComponent>("MovementCom");
	MovementCom->InitialSpeed = 100.0f;
	MovementCom->bInitialVelocityInLocalSpace = true;
	MovementCom->bRotationFollowsVelocity = true;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

