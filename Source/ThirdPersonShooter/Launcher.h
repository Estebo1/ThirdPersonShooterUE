// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "ThirdPersonShooterCharacter.h"
#include "Launcher.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class THIRDPERSONSHOOTER_API ULauncher : public UBoxComponent
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	ULauncher();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Trigger(bool triggerValue);

	UPROPERTY(EditAnywhere)
	bool isPressuerplate{ true };

	UPROPERTY(EditAnywhere)
	bool isTriggered{ false };

	UPROPERTY(EditAnywhere)
	AActor* moveActor;

	UPROPERTY(EditAnywhere)
	float upForce = 10.0f;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* overlappedComp, AActor* other,
		UPrimitiveComponent* otherComp, int32 otherBodyIndex,
		bool bFromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* overlappedComp, AActor* other,
		UPrimitiveComponent* otherComp, int32 otherBodyIndex);

};
