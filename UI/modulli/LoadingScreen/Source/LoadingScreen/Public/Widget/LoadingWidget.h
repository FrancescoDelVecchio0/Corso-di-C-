// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "LoadingWidget.generated.h"

class SLoading;
/**
 * 
 */
UCLASS()
class LOADINGSCREEN_API ULoadingWidget : public UWidget
{
	GENERATED_BODY()

public:
	
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	FSlateBrush RotatingBrush;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	FSlateBrush BackgroundBrush;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	float RotationSpeed = 0.2f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	bool bNeedBackground = true;
 
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif
 
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	TSharedPtr<SLoading> LoadingSlate;
};
