// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_LastPlayerPositionBBB.h"

UBTService_LastPlayerPositionBBB::UBTService_LastPlayerPositionBBB()
{
	NodeName = TEXT("Update Last Known Player Location");
}

void UBTService_LastPlayerPositionBBB::TickNode(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds)
{
	Super::TickNode(ownerComp, nodeMemory, deltaSeconds);

	AEnemyAI* controller = Cast<AEnemyAI>(ownerComp.GetAIOwner());

	AThirdPersonShooterCharacter* player = controller->GetPlayerCharacter();
	UBlackboardComponent* blackboard = controller->GetBlackboardComponent();

	if (player) {
		blackboard->SetValueAsVector(GetSelectedBlackboardKey(), player->GetActorLocation());
	}
}
