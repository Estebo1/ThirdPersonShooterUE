// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyAI.h"
#include "BTServide_PlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UBTServide_PlayerLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTServide_PlayerLocation();

	virtual void TickNode(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds) override;
};
