// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/GameplayEffect/ModMagnitudeCalculations/GMMC_UseLevelAsMagnitude.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGMMC_UseLevelAsMagnitude() {}

// Begin Cross Module References
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayModMagnitudeCalculation();
GASLESSONS_API UClass* Z_Construct_UClass_UGMMC_UseLevelAsMagnitude();
GASLESSONS_API UClass* Z_Construct_UClass_UGMMC_UseLevelAsMagnitude_NoRegister();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Class UGMMC_UseLevelAsMagnitude
void UGMMC_UseLevelAsMagnitude::StaticRegisterNativesUGMMC_UseLevelAsMagnitude()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGMMC_UseLevelAsMagnitude);
UClass* Z_Construct_UClass_UGMMC_UseLevelAsMagnitude_NoRegister()
{
	return UGMMC_UseLevelAsMagnitude::StaticClass();
}
struct Z_Construct_UClass_UGMMC_UseLevelAsMagnitude_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "DisplayName", "Use Level as Magnitude" },
		{ "IncludePath", "GameplayEffect/ModMagnitudeCalculations/GMMC_UseLevelAsMagnitude.h" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ModMagnitudeCalculations/GMMC_UseLevelAsMagnitude.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGMMC_UseLevelAsMagnitude>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UGMMC_UseLevelAsMagnitude_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayModMagnitudeCalculation,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGMMC_UseLevelAsMagnitude_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGMMC_UseLevelAsMagnitude_Statics::ClassParams = {
	&UGMMC_UseLevelAsMagnitude::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGMMC_UseLevelAsMagnitude_Statics::Class_MetaDataParams), Z_Construct_UClass_UGMMC_UseLevelAsMagnitude_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGMMC_UseLevelAsMagnitude()
{
	if (!Z_Registration_Info_UClass_UGMMC_UseLevelAsMagnitude.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGMMC_UseLevelAsMagnitude.OuterSingleton, Z_Construct_UClass_UGMMC_UseLevelAsMagnitude_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGMMC_UseLevelAsMagnitude.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<UGMMC_UseLevelAsMagnitude>()
{
	return UGMMC_UseLevelAsMagnitude::StaticClass();
}
UGMMC_UseLevelAsMagnitude::UGMMC_UseLevelAsMagnitude(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGMMC_UseLevelAsMagnitude);
UGMMC_UseLevelAsMagnitude::~UGMMC_UseLevelAsMagnitude() {}
// End Class UGMMC_UseLevelAsMagnitude

// Begin Registration
struct Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_GameplayEffect_ModMagnitudeCalculations_GMMC_UseLevelAsMagnitude_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGMMC_UseLevelAsMagnitude, UGMMC_UseLevelAsMagnitude::StaticClass, TEXT("UGMMC_UseLevelAsMagnitude"), &Z_Registration_Info_UClass_UGMMC_UseLevelAsMagnitude, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGMMC_UseLevelAsMagnitude), 3131065530U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_GameplayEffect_ModMagnitudeCalculations_GMMC_UseLevelAsMagnitude_h_720415087(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_GameplayEffect_ModMagnitudeCalculations_GMMC_UseLevelAsMagnitude_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_GameplayEffect_ModMagnitudeCalculations_GMMC_UseLevelAsMagnitude_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
