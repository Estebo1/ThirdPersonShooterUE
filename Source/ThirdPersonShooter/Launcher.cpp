// Fill out your copyright notice in the Description page of Project Settings.


#include "Launcher.h"

ULauncher::ULauncher()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void ULauncher::BeginPlay()
{
	Super::BeginPlay();

	
	if (isPressuerplate) {
		OnComponentBeginOverlap.AddDynamic(this, &ULauncher::OnBeginOverlap);
		OnComponentEndOverlap.AddDynamic(this, &ULauncher::OnEndOverlap);
	}
}

void ULauncher::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void ULauncher::Trigger(bool triggerValue)
{
	isTriggered = triggerValue;
}

void ULauncher::OnBeginOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (!otherActor) return;

	if (otherActor && otherActor->ActorHasTag("Player")) {
		AThirdPersonShooterCharacter* player =Cast<AThirdPersonShooterCharacter>(otherActor);
		if (!player) return;

		if (!isTriggered) {
			Trigger(true);
			player->LaunchPlayer(upForce);
			UE_LOG(LogTemp, Warning, TEXT("launch"));
		}
	}
}
void ULauncher::OnEndOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor && otherActor->ActorHasTag("Player")) {
		if (isTriggered) Trigger(false);
	}
}