// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/Controllers/GASPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGASPlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
GASLESSONS_API UClass* Z_Construct_UClass_AGASCharacter_NoRegister();
GASLESSONS_API UClass* Z_Construct_UClass_AGASPlayerController();
GASLESSONS_API UClass* Z_Construct_UClass_AGASPlayerController_NoRegister();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Class AGASPlayerController
void AGASPlayerController::StaticRegisterNativesAGASPlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGASPlayerController);
UClass* Z_Construct_UClass_AGASPlayerController_NoRegister()
{
	return AGASPlayerController::StaticClass();
}
struct Z_Construct_UClass_AGASPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Controllers/GASPlayerController.h" },
		{ "ModuleRelativePath", "Public/Controllers/GASPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GASCharacter_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//@GAS_INTERFACE\n// caching the Character instead of the AbilitySystemComponent because\n// we are assuming that the Character may be expanded for the project\n// so it might be used from other purposes\n" },
#endif
		{ "ModuleRelativePath", "Public/Controllers/GASPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@GAS_INTERFACE\n caching the Character instead of the AbilitySystemComponent because\n we are assuming that the Character may be expanded for the project\n so it might be used from other purposes" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GASCharacter;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGASPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGASPlayerController_Statics::NewProp_GASCharacter = { "GASCharacter", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGASPlayerController, GASCharacter), Z_Construct_UClass_AGASCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GASCharacter_MetaData), NewProp_GASCharacter_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGASPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGASPlayerController_Statics::NewProp_GASCharacter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGASPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGASPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGASPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AGASPlayerController_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(AGASPlayerController, IAbilitySystemInterface), false },  // 2272790346
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGASPlayerController_Statics::ClassParams = {
	&AGASPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AGASPlayerController_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AGASPlayerController_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGASPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AGASPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGASPlayerController()
{
	if (!Z_Registration_Info_UClass_AGASPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGASPlayerController.OuterSingleton, Z_Construct_UClass_AGASPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGASPlayerController.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<AGASPlayerController>()
{
	return AGASPlayerController::StaticClass();
}
AGASPlayerController::AGASPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGASPlayerController);
AGASPlayerController::~AGASPlayerController() {}
// End Class AGASPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGASPlayerController, AGASPlayerController::StaticClass, TEXT("AGASPlayerController"), &Z_Registration_Info_UClass_AGASPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGASPlayerController), 1058044881U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASPlayerController_h_2049784259(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
