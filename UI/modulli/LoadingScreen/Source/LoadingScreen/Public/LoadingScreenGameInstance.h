// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LoadingScreenGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class LOADINGSCREEN_API ULoadingScreenGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Loading Screen")
	TSubclassOf<UUserWidget> LoadingWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Loading Screen")
	float MinimumLoadingScreenDisplayTime = 1.f;
	
	UFUNCTION()
	virtual void BeginLoadingScreen(const FString& MapName);
	UFUNCTION()
	virtual void EndLoadingScreen(UWorld* InLoadedWorld);

protected:
	
	TSharedPtr<SWidget> LoadingSWidgetPtr;
	
};
