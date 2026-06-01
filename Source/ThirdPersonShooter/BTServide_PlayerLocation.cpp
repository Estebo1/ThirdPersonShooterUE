// Fill out your copyright notice in the Description page of Project Settings.


#include "BTServide_PlayerLocation.h"

UBTServide_PlayerLocation::UBTServide_PlayerLocation()
{
	NodeName = TEXT("Update Player Location");
}

void UBTServide_PlayerLocation::TickNode(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds)
{
	Super::TickNode(ownerComp, nodeMemory, deltaSeconds);

	AEnemyAI* controller = Cast<AEnemyAI>(ownerComp.GetAIOwner());
	AThirdPersonShooterCharacter* player = controller->GetPlayerCharacter();
	UBlackboardComponent* blackboard = controller->GetBlackboardComponent();

	if (controller->LineOfSightTo(player) && player->isAlive) {
		controller->SetFocus(player);
		blackboard->SetValueAsVector(GetSelectedBlackboardKey(), player->GetActorLocation());
	}
	else
	{
		controller->ClearFocus(EAIFocusPriority::Gameplay);
		blackboard->ClearValue(GetSelectedBlackboardKey());
	}
}
