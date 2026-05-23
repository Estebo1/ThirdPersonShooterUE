// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Move.h"
#include "triggerComp.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class THIRDPERSONSHOOTER_API UtriggerComp : public UBoxComponent
{
	GENERATED_BODY()

public:
	UtriggerComp();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Trigger(bool triggerValue);

	UPROPERTY(EditAnywhere)
	bool isPressuerplate{ false };

	UPROPERTY(EditAnywhere)
	bool isTriggered{ false };

	UPROPERTY(EditAnywhere)
	AActor* moveActor;

	UMove* moveComp;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* overlappedComp, AActor* other,
		UPrimitiveComponent* otherComp, int32 otherBodyIndex,
		bool bFromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* overlappedComp, AActor* other,
		UPrimitiveComponent* otherComp, int32 otherBodyIndex);

};