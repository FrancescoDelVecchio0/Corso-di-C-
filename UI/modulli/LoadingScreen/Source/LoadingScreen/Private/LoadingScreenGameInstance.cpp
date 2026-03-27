// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadingScreenGameInstance.h"

#include "MoviePlayer.h"
#include "Blueprint/UserWidget.h"

void ULoadingScreenGameInstance::Init()
{
	Super::Init();
 
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &ULoadingScreenGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &ULoadingScreenGameInstance::EndLoadingScreen);
}

void ULoadingScreenGameInstance::BeginLoadingScreen(const FString& MapName)
{
	if (!IsRunningDedicatedServer())
	{
		UUserWidget* LoadingWidget = CreateWidget<UUserWidget>(this, LoadingWidgetClass, TEXT("LoadingScreen"));
		LoadingSWidgetPtr = LoadingWidget->TakeWidget();
 
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.WidgetLoadingScreen = LoadingSWidgetPtr;
		LoadingScreen.bAllowInEarlyStartup = false;
		LoadingScreen.PlaybackType = MT_Normal;
		LoadingScreen.bAllowEngineTick = false;
		LoadingScreen.bWaitForManualStop = false;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = true;
		LoadingScreen.MinimumLoadingScreenDisplayTime = MinimumLoadingScreenDisplayTime;
 
		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
}

void ULoadingScreenGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{
}
