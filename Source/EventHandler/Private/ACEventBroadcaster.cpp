// Fill out your copyright notice in the Description page of Project Settings.


#include "ACEventBroadcaster.h"

#include "EventHandlerSubsystem.h"
#include "GameplayTagContainer.h"


// Sets default values for this component's properties
UACEventBroadcaster::UACEventBroadcaster()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SetIsReplicated(true);
}

void UACEventBroadcaster::ServerBroadcastEvent_Implementation(FGameplayTag EventID)
{
	UEventHandlerSubsystem* EventHandlerSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UEventHandlerSubsystem>();
	EventHandlerSubsystem->BroadcastEventLocal(EventID,nullptr);
}



