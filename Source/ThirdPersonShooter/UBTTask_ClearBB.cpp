// Fill out your copyright notice in the Description page of Project Settings.


#include "UBTTask_ClearBB.h"

UUBTTask_ClearBB::UUBTTask_ClearBB() {
	NodeName = TEXT("Clear Value");
}

EBTNodeResult::Type UUBTTask_ClearBB::ExecuteTask(UBehaviorTreeComponent& root, uint8* nodeMemory)
{
	Super::ExecuteTask(root, nodeMemory);

	UBlackboardComponent* bb = root.GetBlackboardComponent();
	bb->ClearValue(GetSelectedBlackboardKey());
	return EBTNodeResult::Succeeded;
}
