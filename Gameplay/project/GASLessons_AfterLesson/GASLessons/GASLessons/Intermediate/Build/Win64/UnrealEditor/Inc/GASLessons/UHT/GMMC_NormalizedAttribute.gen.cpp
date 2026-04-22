// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/GameplayEffect/ModMagnitudeCalculations/GMMC_NormalizedAttribute.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGMMC_NormalizedAttribute() {}

// Begin Cross Module References
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayModMagnitudeCalculation();
GASLESSONS_API UClass* Z_Construct_UClass_UGMMC_NormalizedAttribute();
GASLESSONS_API UClass* Z_Construct_UClass_UGMMC_NormalizedAttribute_NoRegister();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Class UGMMC_NormalizedAttribute
void UGMMC_NormalizedAttribute::StaticRegisterNativesUGMMC_NormalizedAttribute()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGMMC_NormalizedAttribute);
UClass* Z_Construct_UClass_UGMMC_NormalizedAttribute_NoRegister()
{
	return UGMMC_NormalizedAttribute::StaticClass();
}
struct Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "DisplayName", "Normalized Attribute" },
		{ "IncludePath", "GameplayEffect/ModMagnitudeCalculations/GMMC_NormalizedAttribute.h" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ModMagnitudeCalculations/GMMC_NormalizedAttribute.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAttributeIndex_MetaData[] = {
		{ "Category", "GMMC_NormalizedAttribute" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ModMagnitudeCalculations/GMMC_NormalizedAttribute.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAttributeIndex_MetaData[] = {
		{ "Category", "GMMC_NormalizedAttribute" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ModMagnitudeCalculations/GMMC_NormalizedAttribute.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentAttributeIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAttributeIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGMMC_NormalizedAttribute>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::NewProp_CurrentAttributeIndex = { "CurrentAttributeIndex", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGMMC_NormalizedAttribute, CurrentAttributeIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAttributeIndex_MetaData), NewProp_CurrentAttributeIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::NewProp_MaxAttributeIndex = { "MaxAttributeIndex", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGMMC_NormalizedAttribute, MaxAttributeIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAttributeIndex_MetaData), NewProp_MaxAttributeIndex_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::NewProp_CurrentAttributeIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::NewProp_MaxAttributeIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayModMagnitudeCalculation,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::ClassParams = {
	&UGMMC_NormalizedAttribute::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::PropPointers),
	0,
	0x001000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::Class_MetaDataParams), Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGMMC_NormalizedAttribute()
{
	if (!Z_Registration_Info_UClass_UGMMC_NormalizedAttribute.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGMMC_NormalizedAttribute.OuterSingleton, Z_Construct_UClass_UGMMC_NormalizedAttribute_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGMMC_NormalizedAttribute.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<UGMMC_NormalizedAttribute>()
{
	return UGMMC_NormalizedAttribute::StaticClass();
}
UGMMC_NormalizedAttribute::UGMMC_NormalizedAttribute(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGMMC_NormalizedAttribute);
UGMMC_NormalizedAttribute::~UGMMC_NormalizedAttribute() {}
// End Class UGMMC_NormalizedAttribute

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ModMagnitudeCalculations_GMMC_NormalizedAttribute_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGMMC_NormalizedAttribute, UGMMC_NormalizedAttribute::StaticClass, TEXT("UGMMC_NormalizedAttribute"), &Z_Registration_Info_UClass_UGMMC_NormalizedAttribute, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGMMC_NormalizedAttribute), 383076372U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ModMagnitudeCalculations_GMMC_NormalizedAttribute_h_2790381316(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ModMagnitudeCalculations_GMMC_NormalizedAttribute_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ModMagnitudeCalculations_GMMC_NormalizedAttribute_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
