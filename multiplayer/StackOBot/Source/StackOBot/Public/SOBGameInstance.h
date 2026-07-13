// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SOBGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class STACKOBOT_API USOBGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	virtual void Init() override;
};
