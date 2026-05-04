// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "ThirdPersonShooterCharacter.h"
#include "BehaviorTree/blackboardComponent.h"
#include "EnemyAI.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API AEnemyAI : public AAIController
{
	GENERATED_BODY()
protected:

	AThirdPersonShooterCharacter* playerPawn;

	AThirdPersonShooterCharacter* myCharacter;
	
	UPROPERTY(EditAnywhere)
	UBehaviorTree* enemyTree;
	virtual void BeginPlay() override;
	
	virtual void Tick(float deltaSeconds) override;
	
public:
	void StartBehaiviourTree(AThirdPersonShooterCharacter* character);
	AThirdPersonShooterCharacter* GetPlayerCharacter() const { return playerPawn; };
	AThirdPersonShooterCharacter* GetMyCharacter() const { return myCharacter; };
};
