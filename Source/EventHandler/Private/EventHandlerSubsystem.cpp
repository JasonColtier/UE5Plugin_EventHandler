// Fill out your copyright notice in the Description page of Project Settings.


#include "EventHandlerSubsystem.h"

#include "ACEventBroadcaster.h"
#include "Logging/StructuredLog.h"

void UEventHandlerSubsystem::BroadcastEventLocal(FGameplayTag EventID, UGenericEventPayload* OptionalPayload)
{
	UE_LOGFMT(LogTemp, Log, "Broadcasting new event {0}", EventID.ToString());
	SavedEvents.AddTag(EventID);
	OnEventFiredDelegate.Broadcast(EventID, OptionalPayload);
}

void UEventHandlerSubsystem::BroadcastEventToServer(const FGameplayTag EventID)
{
	APlayerController* LocalPlayer = GetLocaPlayerController(GetWorld());
	if(!LocalPlayer)
	{
		UE_LOGFMT(LogTemp, Error, "No local player found !");
		return;
	}
	
	UActorComponent* ActorComponent = LocalPlayer->GetComponentByClass(UACEventBroadcaster::StaticClass());
	if (!ActorComponent)
	{
		UE_LOGFMT(LogTemp, Error, "Local player {0} doesnt have ACEventBroadcaster component", LocalPlayer->GetName());
		return;
	}
	Cast<UACEventBroadcaster>(ActorComponent)->ServerBroadcastEvent(EventID);
}

void UEventHandlerSubsystem::ClearSavedEvents()
{
	SavedEvents.Reset();
}


APlayerController* UEventHandlerSubsystem::GetLocaPlayerController(UWorld* WorldContext)
{
	if (!WorldContext)
	{
		UE_LOGFMT(LogTemp, Error, "invalid world context");
		return nullptr;
	}

	//we try to get the local pawn
	ULocalPlayer* LocalPlayer = WorldContext->GetFirstLocalPlayerFromController();

	if (IsValid(LocalPlayer))
	{
		return LocalPlayer->PlayerController;
	}
	return nullptr;
}
