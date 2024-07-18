// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "EventHandlerSubsystem.generated.h"

class UACEventBroadcaster;
class ARPCBroadcaster;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEventFired, FGameplayTag, EventID, UGenericEventPayload*, OptionalPayload);

class UGenericEventPayload;
/**
 * 
 */
UCLASS()
class UEventHandlerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BroadcastEventLocal(const FGameplayTag EventID,UGenericEventPayload* OptionalPayload);

	UFUNCTION(BlueprintCallable)
	void BroadcastEventToServer(const FGameplayTag EventID);
	
	UFUNCTION(BlueprintCallable)
	void ClearSavedEvents();

	UPROPERTY(BlueprintAssignable)
	FOnEventFired OnEventFiredDelegate;

	UPROPERTY(BlueprintReadOnly)
	FGameplayTagContainer SavedEvents;

private:
	APlayerController* GetLocaPlayerController(UWorld* WorldContext);
};
