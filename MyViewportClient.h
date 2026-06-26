#pragma once

#include "CoreMinimal.h"
#include "CommonGameViewportClient.h"
#include "MyViewportClient.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class LAYEREDUI_API UMyViewportClient : public UCommonGameViewportClient
{
	GENERATED_BODY()
	
public:
	UMyViewportClient();

	virtual void Init(struct FWorldContext& WorldContext, UGameInstance* OwningGameInstance, bool bCreateNewAudioDevice = true) override;
	virtual void BeginDestroy() override;
	virtual void ReceivedFocus(FViewport* InViewport) override;
	virtual void Activated(FViewport* InViewport, const FWindowActivateEvent& InActivateEvent) override;

	void HandleFocusChanging(const FFocusEvent& FocusEvent, const FWeakWidgetPath& OldFocusedWidgetPath, const TSharedPtr<SWidget>& OldFocusedWidget, const FWidgetPath& NewFocusedWidgetPath, const TSharedPtr<SWidget>& NewFocusedWidget);

	void RestoreLastValidFocus();
	bool ShouldRestoreFocus(const TSharedPtr<SWidget>& NewFocusedWidget) const;
	
protected:
	
	/** Last valid focusable slate widget */
	TWeakPtr<SWidget> LastFocusedWidget = nullptr;

	/** Prevent recursive focus restoration */
	bool bIsRestoringFocus = false;
};
