// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/LoadingWidget.h"
#include "Slate/SLoading.h"

#define LOCTEXT_NAMESPACE "ULoadingWidget"

void ULoadingWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	LoadingSlate.Reset();
}

TSharedRef<SWidget> ULoadingWidget::RebuildWidget()
{
	LoadingSlate = SNew(SLoading)
		.RotatingBrush(&RotatingBrush)
		.BackgroundBrush(&BackgroundBrush)
		.RotationSpeed(RotationSpeed)
		.CurveEaseFunction(ECurveEaseFunction::Linear)
		.bNeedBackground(bNeedBackground);

	return LoadingSlate.ToSharedRef();
}

#if WITH_EDITOR
const FText ULoadingWidget::GetPaletteCategory()
{
	return LOCTEXT("LoadingWidget_PaletteCategory", "Loading Widget");
}
#endif


#undef LOCTEXT_NAMESPACE
