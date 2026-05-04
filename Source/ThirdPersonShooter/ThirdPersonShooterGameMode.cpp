// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdPersonShooterGameMode.h"

AThirdPersonShooterGameMode::AThirdPersonShooterGameMode()
{
	// stub
}

void AThirdPersonShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
	player = Cast<AThirdPersonShooterCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyAI::StaticClass(), enemyArray);

	for (AActor* temp : enemyArray) {
		Cast<AEnemyAI>(temp)->StartBehaiviourTree(player);
	}
}
