// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "EnemyAI.h"
#include "BT_TaskShoot.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UBT_TaskShoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBT_TaskShoot();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& root, uint8* nodeMemonry) override;
	
};
