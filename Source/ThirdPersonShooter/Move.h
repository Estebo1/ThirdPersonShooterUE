// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Move.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDPERSONSHOOTER_API UMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetShouldMove(bool move);

	bool GetShouldMove() const;

	UPROPERTY(EditAnywhere)
	FVector moveOffset;

	FVector targetLocation;

	FVector StartLocation;

	UPROPERTY(EditAnywhere)
	float moveTime;
	bool reachedTarget{ true };
	UPROPERTY(EditAnywhere)
	bool ShouldMove{ false };

};
