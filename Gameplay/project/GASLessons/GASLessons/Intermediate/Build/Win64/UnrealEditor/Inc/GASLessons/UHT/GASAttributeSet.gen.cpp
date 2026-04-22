// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/AttributeSets/GASAttributeSet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGASAttributeSet() {}

// Begin Cross Module References
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAttributeSet();
GASLESSONS_API UClass* Z_Construct_UClass_UGASAttributeSet();
GASLESSONS_API UClass* Z_Construct_UClass_UGASAttributeSet_NoRegister();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Class UGASAttributeSet
void UGASAttributeSet::StaticRegisterNativesUGASAttributeSet()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGASAttributeSet);
UClass* Z_Construct_UClass_UGASAttributeSet_NoRegister()
{
	return UGASAttributeSet::StaticClass();
}
struct Z_Construct_UClass_UGASAttributeSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AttributeSets/GASAttributeSet.h" },
		{ "ModuleRelativePath", "Public/AttributeSets/GASAttributeSet.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGASAttributeSet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UGASAttributeSet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAttributeSet,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGASAttributeSet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGASAttributeSet_Statics::ClassParams = {
	&UGASAttributeSet::StaticClass,
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
	0x003000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGASAttributeSet_Statics::Class_MetaDataParams), Z_Construct_UClass_UGASAttributeSet_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGASAttributeSet()
{
	if (!Z_Registration_Info_UClass_UGASAttributeSet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGASAttributeSet.OuterSingleton, Z_Construct_UClass_UGASAttributeSet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGASAttributeSet.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<UGASAttributeSet>()
{
	return UGASAttributeSet::StaticClass();
}
UGASAttributeSet::UGASAttributeSet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGASAttributeSet);
UGASAttributeSet::~UGASAttributeSet() {}
// End Class UGASAttributeSet

// Begin Registration
struct Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_GASAttributeSet_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGASAttributeSet, UGASAttributeSet::StaticClass, TEXT("UGASAttributeSet"), &Z_Registration_Info_UClass_UGASAttributeSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGASAttributeSet), 1312457984U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_GASAttributeSet_h_173941808(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_GASAttributeSet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_GASAttributeSet_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
