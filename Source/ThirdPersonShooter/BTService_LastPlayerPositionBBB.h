// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "EnemyAI.h"
#include "BTService_LastPlayerPositionBBB.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UBTService_LastPlayerPositionBBB : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_LastPlayerPositionBBB();

	virtual void TickNode(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds) override;
	
};
