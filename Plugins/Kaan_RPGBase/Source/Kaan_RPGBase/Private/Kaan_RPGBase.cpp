// Copyright Epic Games, Inc. All Rights Reserved.

#include "Kaan_RPGBase.h"

#define LOCTEXT_NAMESPACE "FKaan_RPGBaseModule"

void FKaan_RPGBaseModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FKaan_RPGBaseModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FKaan_RPGBaseModule, Kaan_RPGBase)