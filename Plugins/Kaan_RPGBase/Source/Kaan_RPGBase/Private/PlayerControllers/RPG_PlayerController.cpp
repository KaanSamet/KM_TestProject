// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllers/RPG_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

ARPG_PlayerController::ARPG_PlayerController()
{
	bReplicates = true;

}

void ARPG_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Crash If InputMappingContext is invalid.
	check(RPG_CharacterContext)

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(RPG_CharacterContext, 0);

	/*bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);

	SetInputMode(InputModeData);*/
}

void ARPG_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(RPG_CharacterMoveInputAction3D, ETriggerEvent::Triggered, this, &ARPG_PlayerController::Move2D_AndJump);
	EnhancedInputComponent->BindAction(RPG_CharacterTurnCameraAction, ETriggerEvent::Triggered, this, &ARPG_PlayerController::TurnCamera);
}

void ARPG_PlayerController::Move2D_AndJump(const FInputActionValue& InputActionValue)
{
	const FVector InputAxis3D_Vector = InputActionValue.Get<FVector>();

	// Get controller forward vector
	const FRotator ControllerYawRotation(0.f, GetControlRotation().Yaw, 0.f);

	const FVector ControllerForwardVector = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::X);
	const FVector ControllerRightVector = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::Y);

	TObjectPtr<ACharacter> ControlledCharacter = GetCharacter();

	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, *InputAxis3D_Vector.ToString());

	if (ControlledCharacter == nullptr)
	{
		return;
	}

	ControlledCharacter->AddMovementInput(ControllerForwardVector, InputAxis3D_Vector.X);
	ControlledCharacter->AddMovementInput(ControllerRightVector, InputAxis3D_Vector.Y);

	if (InputAxis3D_Vector.Z != 0)
	{
		ControlledCharacter->Jump();
	}
}

void ARPG_PlayerController::TurnCamera(const FInputActionValue& InputActionValue)
{
	const FVector2D TurnCamera2D_Value = InputActionValue.Get<FVector2D>();

	const float TurnCamera_X = TurnCamera2D_Value.X;
	const float TurnCamera_Y = TurnCamera2D_Value.Y;

	AddYawInput(TurnCamera2D_Value.X);
	AddPitchInput(TurnCamera2D_Value.Y);
}
