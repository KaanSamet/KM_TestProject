// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "DynamicSky.generated.h"

class UDirectionalLightComponent;
class USkyAtmosphereComponent;
class USkyLightComponent;
class UExponentialHeightFogComponent;
class UPostProcessComponent;

UCLASS()
class KAAN_WEATHERBASE_API ADynamicSky : public AActor
{
	GENERATED_BODY()
	
public:	
	ADynamicSky();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	TObjectPtr<USceneComponent> SceneRootComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	TObjectPtr<UDirectionalLightComponent> SunDirectionalLightComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	TObjectPtr<UDirectionalLightComponent> MoonDirectionalLightComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	TObjectPtr<USkyAtmosphereComponent> SkyAtmosphereComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	TObjectPtr<USkyLightComponent> SkyLightComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	TObjectPtr<UExponentialHeightFogComponent> ExponentialHeightFogComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	TObjectPtr<UPostProcessComponent> PostProcessComponent;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01-Time", meta = (ClampMin = "0.0", ClampMax = "24.0", UIMin = "0.0", UIMax = "24.0"))
	float TimeOfTheDay = 12.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01-Time", meta = (ClampMin = "5.0", ClampMax = "7.0", UIMin = "5.0", UIMax = "7.0"))
	float DawnTime = 6.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01-Time", meta = (ClampMin = "17.0", ClampMax = "19.0", UIMin = "17.0", UIMax = "19.0"))
	float DuskTime = 18.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01-Time", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float TransitionTime = 0.3f;


protected:
	UFUNCTION(BlueprintCallable)
	void HandleSunAndMoonRotation(float SpecifiedTimeOfTheDay, float SpecifiedDawnTime, float SpecifiedDuskTime);

};
