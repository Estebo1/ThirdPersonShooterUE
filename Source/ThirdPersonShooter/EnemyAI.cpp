// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAI.h"

void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();
	playerPawn = Cast<AThirdPersonShooterCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
	if (playerPawn) {
		SetFocus(playerPawn);
	}
}

void AEnemyAI::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);
	
	//MoveToActor(playerPawn);
}

void AEnemyAI::StartBehaiviourTree(AThirdPersonShooterCharacter* character)
{
	if (enemyTree) {
		myCharacter = Cast<AThirdPersonShooterCharacter>(GetPawn());
		playerPawn = character;

		RunBehaviorTree(enemyTree);
		if (myCharacter || playerPawn) {
			UBlackboardComponent* blackboardComp = GetBlackboardComponent();
			if (blackboardComp) {
				GetBlackboardComponent()->SetValueAsVector("StartLocation", myCharacter->GetActorLocation());
				GetBlackboardComponent()->SetValueAsVector("PlayerLocation", playerPawn->GetActorLocation());
			}
		}
	}
}
