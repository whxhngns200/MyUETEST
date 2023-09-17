// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/CharacterMovementComponent.h>
#include "Animation/AnimMontage.h"
#include "TimerManager.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	UE_LOG(LogTemp, Warning, TEXT("111111111111111"));
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringCom = CreateDefaultSubobject<USpringArmComponent>("SpringCom");
	SpringCom->SetupAttachment(RootComponent);
	SpringCom->bUsePawnControlRotation = true;
	CamCom = CreateDefaultSubobject<UCameraComponent>("CamCom");
	CamCom->SetupAttachment(SpringCom);
	InteractComp = CreateDefaultSubobject<UMyInteractionComponent>("InteractComp");
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCharacter::MoveForward(float value)
{
	FRotator rotator = GetControlRotation();
	rotator.Roll = 0.0f;
	rotator.Pitch = 0.0f;
	//AddMovementInput(GetActorForwardVector(), value);
	AddMovementInput(rotator.Vector(), value);
}
void AMyCharacter::MoveRight(float value)
{
	FRotator rotator = GetControlRotation();
	rotator.Roll = 0.0f;
	rotator.Pitch = 0.0f;

	FVector fv = FRotationMatrix(rotator).GetScaledAxis(EAxis::Y);
	AddMovementInput(fv, value);
}

void AMyCharacter::PrimaryAttack()
{
	PlayAnimMontage(AnimMontage);
	UE_LOG(LogTemp, Warning, TEXT("2222222222222 PrimaryAttack"));
	GetWorldTimerManager().SetTimer(PrimaryAttackTimerHandle, this, &AMyCharacter::PrimaryAttack_TimeElapsed, 0.2f);
}

void AMyCharacter::PrimaryInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("3333333 PrimaryInteract"));
	InteractComp->PrimaryInteract();
}

void AMyCharacter::PrimaryAttack_TimeElapsed()
{
	//ProjectileClass
	FVector HandLocation = GetMesh()->GetSocketLocation("Muzzle_01");
	FTransform SpawnTM = FTransform(GetControlRotation(), HandLocation);
	FActorSpawnParameters  SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParams);
	UE_LOG(LogTemp, Warning, TEXT("222 今日天气:%s,温度:%.2f, 湿度:%.2f,"), TEXT("多云转晴"), 23.5f, 16.8f);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AMyCharacter::PrimaryAttack);
	
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &AMyCharacter::PrimaryInteract);
}

