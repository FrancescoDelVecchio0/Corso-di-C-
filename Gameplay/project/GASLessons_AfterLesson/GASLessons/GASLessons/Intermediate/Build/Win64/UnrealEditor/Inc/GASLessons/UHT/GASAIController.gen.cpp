// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/Controllers/GASAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGASAIController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
GASLESSONS_API UClass* Z_Construct_UClass_AGASAIController();
GASLESSONS_API UClass* Z_Construct_UClass_AGASAIController_NoRegister();
GASLESSONS_API UClass* Z_Construct_UClass_AGASCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Class AGASAIController
void AGASAIController::StaticRegisterNativesAGASAIController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGASAIController);
UClass* Z_Construct_UClass_AGASAIController_NoRegister()
{
	return AGASAIController::StaticClass();
}
struct Z_Construct_UClass_AGASAIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Controllers/GASAIController.h" },
		{ "ModuleRelativePath", "Public/Controllers/GASAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GASCharacter_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//@GAS_INTERFACE\n// caching the Character instead of the AbilitySystemComponent because\n// we are assuming that the Character may be expanded for the project\n// so it might be used from other purposes\n" },
#endif
		{ "ModuleRelativePath", "Public/Controllers/GASAIController.h" },
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
		TCppClassTypeTraits<AGASAIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGASAIController_Statics::NewProp_GASCharacter = { "GASCharacter", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGASAIController, GASCharacter), Z_Construct_UClass_AGASCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GASCharacter_MetaData), NewProp_GASCharacter_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGASAIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGASAIController_Statics::NewProp_GASCharacter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGASAIController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGASAIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGASAIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AGASAIController_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(AGASAIController, IAbilitySystemInterface), false },  // 2272790346
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGASAIController_Statics::ClassParams = {
	&AGASAIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AGASAIController_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AGASAIController_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGASAIController_Statics::Class_MetaDataParams), Z_Construct_UClass_AGASAIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGASAIController()
{
	if (!Z_Registration_Info_UClass_AGASAIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGASAIController.OuterSingleton, Z_Construct_UClass_AGASAIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGASAIController.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<AGASAIController>()
{
	return AGASAIController::StaticClass();
}
AGASAIController::AGASAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGASAIController);
AGASAIController::~AGASAIController() {}
// End Class AGASAIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Controllers_GASAIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGASAIController, AGASAIController::StaticClass, TEXT("AGASAIController"), &Z_Registration_Info_UClass_AGASAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGASAIController), 437978390U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Controllers_GASAIController_h_916251363(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Controllers_GASAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Controllers_GASAIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
