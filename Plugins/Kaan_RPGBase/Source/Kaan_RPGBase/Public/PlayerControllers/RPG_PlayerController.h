// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPG_PlayerController.generated.h"

/**
 * 
 * @param asfsafs		jkmwmjfwkmjkf
 * @param fjewjfwefw	jewfsdufhjnew
 * 
 * @return asfjasfjsa	adsjfsdnafnhjsd
 * 
 */

class UInputMappingContext;
class UInputAction;

struct FInputActionValue;

UCLASS()
class KAAN_RPGBASE_API ARPG_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ARPG_PlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	

private:
	//InputMappingContext variable to set from blueprint.
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputMappingContext> RPG_CharacterContext;

	//InputAction variable to set from blueprint.
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> RPG_CharacterMoveInputAction3D;

	//InputAction variable to set from blueprint.
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> RPG_CharacterTurnCameraAction;


	void Move2D_AndJump(const FInputActionValue& InputActionValue);
	void TurnCamera(const FInputActionValue& InputActionValue);
};
