// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DynamicSky.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/SkyAtmosphereComponent.h"
#include "Components/SkyLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/PostProcessComponent.h"

#include "Kismet/KismetMathLibrary.h"

ADynamicSky::ADynamicSky()
{
	PrimaryActorTick.bCanEverTick = true;

	// Do basic setup and component addition

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRootComponent);

	SunDirectionalLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("SunDirectionalLight"));
	SunDirectionalLightComponent->SetupAttachment(GetRootComponent());
	SunDirectionalLightComponent->ForwardShadingPriority = 1;

	MoonDirectionalLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("MoonDirectionalLight"));
	MoonDirectionalLightComponent->SetupAttachment(GetRootComponent());
	MoonDirectionalLightComponent->ForwardShadingPriority = 0;
	MoonDirectionalLightComponent->Intensity = 2.f;

	SkyAtmosphereComponent = CreateDefaultSubobject<USkyAtmosphereComponent>(TEXT("SkyAtmosphere"));
	SkyAtmosphereComponent->SetupAttachment(GetRootComponent());

	SkyLightComponent = CreateDefaultSubobject<USkyLightComponent>(TEXT("SkyLight"));
	SkyLightComponent->SetupAttachment(GetRootComponent());
	SkyLightComponent->bRealTimeCapture = true;

	ExponentialHeightFogComponent = CreateDefaultSubobject<UExponentialHeightFogComponent>(TEXT("ExponentialHeightFog"));
	ExponentialHeightFogComponent->SetupAttachment(GetRootComponent());

	PostProcessComponent = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcess"));
	PostProcessComponent->bUnbound = true;



}

void ADynamicSky::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADynamicSky::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADynamicSky::HandleSunAndMoonRotation(float SpecifiedTimeOfTheDay, float SpecifiedDawnTime, float SpecifiedDuskTime)
{
	if (SpecifiedTimeOfTheDay >= SpecifiedDawnTime && SpecifiedTimeOfTheDay <= SpecifiedDuskTime)
	{
		SunDirectionalLightComponent->SetWorldRotation(
			FRotator(UKismetMathLibrary::MapRangeUnclamped(SpecifiedTimeOfTheDay, SpecifiedDawnTime, SpecifiedDuskTime, 0.f, -180.f), 0.f, 0.f));
		MoonDirectionalLightComponent->SetWorldRotation(
			FRotator(90.f, 0.f, 0.f));
	}
	else
	{
		MoonDirectionalLightComponent->SetWorldRotation(
			FRotator(UKismetMathLibrary::MapRangeUnclamped(SpecifiedTimeOfTheDay, SpecifiedDawnTime, SpecifiedDuskTime, 0.f, -180.f), 0.f, 0.f)*-1);
		SunDirectionalLightComponent->SetWorldRotation(
			FRotator(90.f, 0.f, 0.f));
	}
	
}
