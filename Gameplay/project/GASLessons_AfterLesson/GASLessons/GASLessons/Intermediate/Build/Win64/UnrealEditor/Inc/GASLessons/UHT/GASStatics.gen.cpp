// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/GASStatics.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGASStatics() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
GASLESSONS_API UClass* Z_Construct_UClass_UGASStatics();
GASLESSONS_API UClass* Z_Construct_UClass_UGASStatics_NoRegister();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Class UGASStatics
void UGASStatics::StaticRegisterNativesUGASStatics()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGASStatics);
UClass* Z_Construct_UClass_UGASStatics_NoRegister()
{
	return UGASStatics::StaticClass();
}
struct Z_Construct_UClass_UGASStatics_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GASStatics.h" },
		{ "ModuleRelativePath", "Public/GASStatics.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGASStatics>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UGASStatics_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGASStatics_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGASStatics_Statics::ClassParams = {
	&UGASStatics::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGASStatics_Statics::Class_MetaDataParams), Z_Construct_UClass_UGASStatics_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGASStatics()
{
	if (!Z_Registration_Info_UClass_UGASStatics.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGASStatics.OuterSingleton, Z_Construct_UClass_UGASStatics_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGASStatics.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<UGASStatics>()
{
	return UGASStatics::StaticClass();
}
UGASStatics::UGASStatics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGASStatics);
UGASStatics::~UGASStatics() {}
// End Class UGASStatics

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GASStatics_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGASStatics, UGASStatics::StaticClass, TEXT("UGASStatics"), &Z_Registration_Info_UClass_UGASStatics, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGASStatics), 746412890U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GASStatics_h_1579059295(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GASStatics_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GASStatics_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
