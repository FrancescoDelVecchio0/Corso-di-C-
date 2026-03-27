// Fill out your copyright notice in the Description page of Project Settings.


#include "Slate/SLoading.h"

void SLoading::Construct(const FArguments& InArgs)
{
	RotatingBrush = InArgs._RotatingBrush;
	BackgroundBrush = InArgs._BackgroundBrush;
	bNeedBackground = InArgs._bNeedBackground;
	RotationSpeed = InArgs._RotationSpeed;
	CurveEaseFunction = InArgs._CurveEaseFunction;

	Animation = FCurveSequence();
	CurveHandle = Animation.AddCurve(0, 60.f, CurveEaseFunction);

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SImage)
			.Image(BackgroundBrush)
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SImage)
			.Image(RotatingBrush)
			.RenderTransformPivot(FVector2D(0.5, 0.5))
			.RenderTransform_Lambda([this]()
			{
				return FSlateRenderTransform(FQuat2D(CurveHandle.GetLerp() * 360.f * RotationSpeed));
			})
		]
	];

	Animation.Play(AsShared(), true, 0.f, false);
}

void SLoading::SetRotatingBrush(const FSlateBrush* InRotatingBrush)
{
	RotatingBrush = InRotatingBrush;
}

void SLoading::SetBackgroundBrush(const FSlateBrush* InBackgroundBrush)
{
	BackgroundBrush = InBackgroundBrush;
}

void SLoading::SetRotationSpeed(float InRotationSpeed)
{
	RotationSpeed = InRotationSpeed;
}

void SLoading::SetNeedBackground(bool bInNeedBackground)
{
	bNeedBackground = bInNeedBackground;
}

void SLoading::SetCurveEaseFunction(ECurveEaseFunction InCurveEaseFunction)
{
	CurveEaseFunction = InCurveEaseFunction;
}
