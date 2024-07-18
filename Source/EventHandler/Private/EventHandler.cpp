// Copyright Epic Games, Inc. All Rights Reserved.

#include "EventHandler.h"

#include "GameplayTagsManager.h"

#define LOCTEXT_NAMESPACE "FEventHandlerModule"

void FEventHandlerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UGameplayTagsManager::Get().AddTagIniSearchPath(FPaths::ProjectPluginsDir() / TEXT("UE5Plugin_EventHandler/Config/Tags"));
}

void FEventHandlerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEventHandlerModule, EventHandler)