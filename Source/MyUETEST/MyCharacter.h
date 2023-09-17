// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <MyInteractionComponent.h>
#include "MyCharacter.generated.h"




class USpringArmComponent;
class UCameraComponent;
class UAnimMontage;

UCLASS()
class MYUETEST_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;
	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage *AnimMontage;

	FTimerHandle PrimaryAttackTimerHandle;

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringCom;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CamCom;
	UPROPERTY(VisibleAnywhere)
	UMyInteractionComponent *InteractComp;

	void MoveForward(float value); 
	void MoveRight(float value);
	void PrimaryAttack();
	void PrimaryInteract();
	void PrimaryAttack_TimeElapsed();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
