// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ThirdPersonShooterCharacter.h"
#include "EnemyAI.h"
#include "ThirdPersonShooterGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AThirdPersonShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	AThirdPersonShooterGameMode();

protected:

	virtual void BeginPlay() override;
	AThirdPersonShooterCharacter* player;
	TArray<AActor*> enemyArray;
};



