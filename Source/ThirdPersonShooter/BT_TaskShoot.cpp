// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_TaskShoot.h"

UBT_TaskShoot::UBT_TaskShoot()
{
}

EBTNodeResult::Type UBT_TaskShoot::ExecuteTask(UBehaviorTreeComponent& root, uint8* nodeMemonry)
{
	Super::ExecuteTask(root, nodeMemonry);

	AEnemyAI* controller = Cast<AEnemyAI>(root.GetAIOwner());
	AThirdPersonShooterCharacter* myCharacter = controller->GetMyCharacter();

	if (controller->GetPlayerCharacter()->isAlive) {
		myCharacter->Shoot();
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}

