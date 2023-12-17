// Fill out your copyright notice in the Description page of Project Settings.


#include "RPG_Characters/Base/RPG_CharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


ARPG_CharacterBase::ARPG_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	CameraSpring = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpring"));
	CameraSpring->SetupAttachment(GetRootComponent());
	CameraSpring->bUsePawnControlRotation = true;	// Turn camera with controller rotation with MouseX-MouseY input
	CameraSpring->TargetArmLength = 400.f;
	

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraSpring);
	if (GetCharacterMovement())	{GetCharacterMovement()->bOrientRotationToMovement = true;}

	
}

void ARPG_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARPG_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARPG_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

