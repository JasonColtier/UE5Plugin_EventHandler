// Fill out your copyright notice in the Description page of Project Settings.


#include "EventHandlerSubsystem.h"

#include "Logging/StructuredLog.h"

void UEventHandlerSubsystem::BroadcastEvent(FGameplayTag EventID, UGenericEventPayload* OptionalPayload)
{
	UE_LOGFMT(LogTemp, Log, "Broadcasting new event {0}", EventID.ToString());
	SavedEvents.AddTag(EventID);
	OnEventFiredDelegate.Broadcast(EventID,OptionalPayload);
}

void UEventHandlerSubsystem::ClearSavedEvents()
{
	SavedEvents.Reset();
}
