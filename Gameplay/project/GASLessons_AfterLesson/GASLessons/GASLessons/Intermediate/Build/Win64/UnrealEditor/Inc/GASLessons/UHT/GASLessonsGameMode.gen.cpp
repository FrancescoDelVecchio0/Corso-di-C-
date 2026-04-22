// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/GASLessonsGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGASLessonsGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
GASLESSONS_API UClass* Z_Construct_UClass_AGASLessonsGameMode();
GASLESSONS_API UClass* Z_Construct_UClass_AGASLessonsGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Class AGASLessonsGameMode
void AGASLessonsGameMode::StaticRegisterNativesAGASLessonsGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGASLessonsGameMode);
UClass* Z_Construct_UClass_AGASLessonsGameMode_NoRegister()
{
	return AGASLessonsGameMode::StaticClass();
}
struct Z_Construct_UClass_AGASLessonsGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GASLessonsGameMode.h" },
		{ "ModuleRelativePath", "GASLessonsGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGASLessonsGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGASLessonsGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGASLessonsGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGASLessonsGameMode_Statics::ClassParams = {
	&AGASLessonsGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGASLessonsGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AGASLessonsGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGASLessonsGameMode()
{
	if (!Z_Registration_Info_UClass_AGASLessonsGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGASLessonsGameMode.OuterSingleton, Z_Construct_UClass_AGASLessonsGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGASLessonsGameMode.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<AGASLessonsGameMode>()
{
	return AGASLessonsGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGASLessonsGameMode);
AGASLessonsGameMode::~AGASLessonsGameMode() {}
// End Class AGASLessonsGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_GASLessonsGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGASLessonsGameMode, AGASLessonsGameMode::StaticClass, TEXT("AGASLessonsGameMode"), &Z_Registration_Info_UClass_AGASLessonsGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGASLessonsGameMode), 1653662999U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_GASLessonsGameMode_h_252180251(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_GASLessonsGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_GASLessonsGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
