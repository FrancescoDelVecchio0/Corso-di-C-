#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SLoading : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLoading){	}

		SLATE_ARGUMENT(const FSlateBrush*, RotatingBrush)
		SLATE_ARGUMENT(const FSlateBrush*, BackgroundBrush)
		SLATE_ARGUMENT(float, RotationSpeed)
		SLATE_ARGUMENT(bool, bNeedBackground)
		SLATE_ARGUMENT(ECurveEaseFunction, CurveEaseFunction)
		
	SLATE_END_ARGS()	
	
	void Construct(const FArguments& InArgs);
	
	void SetRotatingBrush(const FSlateBrush* InRotatingBrush);
	void SetBackgroundBrush(const FSlateBrush* InBackgroundBrush);
	void SetRotationSpeed(float InRotationSpeed);
	void SetNeedBackground(bool bInNeedBackground);
	void SetCurveEaseFunction(ECurveEaseFunction InCurveEaseFunction);

private:
	FCurveSequence Animation;
	FCurveHandle CurveHandle;
	
	const FSlateBrush* RotatingBrush = nullptr;
	const FSlateBrush* BackgroundBrush  = nullptr;
	float RotationSpeed = 0.2f;	
	ECurveEaseFunction CurveEaseFunction = ECurveEaseFunction::Linear;
	bool bNeedBackground = true;
};
