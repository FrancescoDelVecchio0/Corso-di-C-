
#include "System/MyViewportClient.h"
#include "Slate/SObjectWidget.h"
#include "Widgets/SViewport.h"

class UGameInstance;

UMyViewportClient::UMyViewportClient()
	: Super(FObjectInitializer::Get())
{
}

void UMyViewportClient::Init(struct FWorldContext& WorldContext, UGameInstance* OwningGameInstance, bool bCreateNewAudioDevice)
{
	Super::Init(WorldContext, OwningGameInstance, bCreateNewAudioDevice);

#if PLATFORM_DESKTOP
	FSlateApplication::Get().OnFocusChanging().AddUObject(this, &UMyViewportClient::HandleFocusChanging);
#endif
}

void UMyViewportClient::BeginDestroy()
{
#if PLATFORM_DESKTOP
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().OnFocusChanging().RemoveAll(this);
	}
#endif

	Super::BeginDestroy();
}

void UMyViewportClient::ReceivedFocus(FViewport* InViewport)
{
	Super::ReceivedFocus(InViewport);
	RestoreLastValidFocus();
}

void UMyViewportClient::Activated(FViewport* InViewport, const FWindowActivateEvent& InActivateEvent)
{
	Super::Activated(InViewport, InActivateEvent);
	RestoreLastValidFocus();
}

void UMyViewportClient::HandleFocusChanging(const FFocusEvent& FocusEvent, const FWeakWidgetPath& OldFocusedWidgetPath, const TSharedPtr<SWidget>& OldFocusedWidget, const FWidgetPath& NewFocusedWidgetPath, const TSharedPtr<SWidget>& NewFocusedWidget)
{
#if PLATFORM_DESKTOP
	if (bIsRestoringFocus)
	{
		return;
	}

	// Track ONLY SObjectWidget UMG/CommonUI widgets
	TSharedPtr<SWidget> Widget = NewFocusedWidget;
	while (Widget.IsValid())
	{
		if (Widget->GetType().IsEqual(TEXT("SObjectWidget")))
		{
			if (UWidget* CandidateWidget = Cast<UWidget>(StaticCastSharedRef<SObjectWidget>(Widget.ToSharedRef())->GetWidgetObject()))
			{
				LastFocusedWidget = CandidateWidget->TakeWidget();
				break;
			}
		}

		Widget = Widget->GetParentWidget();
	}

	if (ShouldRestoreFocus(NewFocusedWidget))
	{
		RestoreLastValidFocus();
	}
#endif
}

void UMyViewportClient::RestoreLastValidFocus()
{
#if PLATFORM_DESKTOP
	if (bIsRestoringFocus)
	{
		return;
	}

	TSharedPtr<SWidget> WidgetToFocus = LastFocusedWidget.Pin();
	if (!WidgetToFocus.IsValid())
	{
		return;
	}

	if (WidgetToFocus->HasAnyUserFocus())
	{
		return;
	}

	bIsRestoringFocus = true;

	// Defer to next tick to avoid Slate re-entrancy issues
	AsyncTask(ENamedThreads::GameThread, [WeakWidget = LastFocusedWidget, this]()
	{
		if (!FSlateApplication::IsInitialized())
		{
			bIsRestoringFocus = false;
			return;
		}

		TSharedPtr<SWidget> PinnedWidget = WeakWidget.Pin();
		if (PinnedWidget.IsValid())
		{
			FSlateApplication::Get().SetUserFocus(0, PinnedWidget, EFocusCause::SetDirectly);
#if WITH_EDITOR
			TSharedPtr<SObjectWidget> ObjectWidget = StaticCastSharedPtr<SObjectWidget>(PinnedWidget);
			if (UWidget* ObjectWidgetPtr = ObjectWidget->GetWidgetObject())
			{
				UE_LOG(LogTemp, Warning, TEXT( "[Focus Restore] UMG: %s Class: %s" ), ObjectWidgetPtr ? *ObjectWidgetPtr->GetName() : TEXT("null"), ObjectWidgetPtr ? *ObjectWidgetPtr->GetClass()->GetName() : TEXT("null"));
			}
#endif
		}

		bIsRestoringFocus = false;
	});
#endif
}

bool UMyViewportClient::ShouldRestoreFocus(const TSharedPtr<SWidget>& NewFocusedWidget) const
{
	// Lost focus entirely or Focus moved to viewport/background
	const bool bViewportLostFocus = !NewFocusedWidget.IsValid() || NewFocusedWidget->GetType().IsEqual(TEXT("SViewport"));
	return bViewportLostFocus;
}
