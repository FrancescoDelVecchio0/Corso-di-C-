// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGASLessons_init() {}
	GASLESSONS_API UFunction* Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GASLessons;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GASLessons()
	{
		if (!Z_Registration_Info_UPackage__Script_GASLessons.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/GASLessons",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xB6F15891,
				0xD65AA9BC,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GASLessons.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_GASLessons.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GASLessons(Z_Construct_UPackage__Script_GASLessons, TEXT("/Script/GASLessons"), Z_Registration_Info_UPackage__Script_GASLessons, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xB6F15891, 0xD65AA9BC));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
