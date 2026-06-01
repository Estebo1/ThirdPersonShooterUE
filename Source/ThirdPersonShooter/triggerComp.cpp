// Fill out your copyright notice in the Description page of Project Settings.


#include "triggerComp.h"

UtriggerComp::UtriggerComp()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UtriggerComp::BeginPlay()
{
	Super::BeginPlay();

	if (moveActor) {
		moveComp = moveActor->FindComponentByClass<UMove>();
	}
	if (isPressuerplate) {
		OnComponentBeginOverlap.AddDynamic(this, &UtriggerComp::OnBeginOverlap);
		OnComponentEndOverlap.AddDynamic(this, &UtriggerComp::OnEndOverlap);
	}
}

void UtriggerComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UtriggerComp::Trigger(bool triggerValue)
{
	isTriggered = triggerValue;
	if (moveComp) moveComp->SetShouldMove(true);
	
}

void UtriggerComp::OnBeginOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor && otherActor->ActorHasTag("Player")) {
		if (!isTriggered) {
			Trigger(true);
			
		}
	}
}
void UtriggerComp::OnEndOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor && otherActor->ActorHasTag("Player")) {
		if (!isTriggered) Trigger(false);
	}
}