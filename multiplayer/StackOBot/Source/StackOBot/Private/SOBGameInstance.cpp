// Fill out your copyright notice in the Description page of Project Settings.


#include "SOBGameInstance.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystem.h"

void USOBGameInstance::Init()
{
	Super::Init();

	const IOnlineSubsystem* OnlineSub = Online::GetSubsystem(GetWorld());
	check(OnlineSub);
	const IOnlineIdentityPtr IdentityInterface = OnlineSub->GetIdentityInterface();
	check(IdentityInterface.IsValid());
	IdentityInterface->AutoLogin(0);
	
	// IOnlineSubsystem* OnlineSub = Online::GetSubsystem(GetWorld());
	// if (OnlineSub)
	// {
	// 	IOnlineIdentityPtr IdentityInterface = OnlineSub->GetIdentityInterface();
	// 	if (IdentityInterface.IsValid())
	// 	{
	// 		FOnlineAccountCredentials Credentials;
    //        
	// 		Credentials.Type = TEXT("developer"); 
	// 		Credentials.Id = TEXT("127.0.0.1:8081");
	// 		Credentials.Token = TEXT("Ste");
	//
	// 		IdentityInterface->Login(0, Credentials);
	// 	}
	// }
}
