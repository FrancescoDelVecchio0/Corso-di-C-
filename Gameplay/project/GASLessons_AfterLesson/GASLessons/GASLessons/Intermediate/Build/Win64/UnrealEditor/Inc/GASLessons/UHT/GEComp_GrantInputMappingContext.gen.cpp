// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/GameplayEffect/Components/GEComp_GrantInputMappingContext.h"
#include "GameplayAbilities/Public/GameplayEffect.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGEComp_GrantInputMappingContext() {}

// Begin Cross Module References
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffectComponent();
GASLESSONS_API UClass* Z_Construct_UClass_UGEComp_GrantInputMappingContext();
GASLESSONS_API UClass* Z_Construct_UClass_UGEComp_GrantInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Class UGEComp_GrantInputMappingContext
void UGEComp_GrantInputMappingContext::StaticRegisterNativesUGEComp_GrantInputMappingContext()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGEComp_GrantInputMappingContext);
UClass* Z_Construct_UClass_UGEComp_GrantInputMappingContext_NoRegister()
{
	return UGEComp_GrantInputMappingContext::StaticClass();
}
struct Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GameplayEffect/Components/GEComp_GrantInputMappingContext.h" },
		{ "ModuleRelativePath", "Public/GameplayEffect/Components/GEComp_GrantInputMappingContext.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingToApply_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/GameplayEffect/Components/GEComp_GrantInputMappingContext.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bForceImmediately_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/GameplayEffect/Components/GEComp_GrantInputMappingContext.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireInputRemapping_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/GameplayEffect/Components/GEComp_GrantInputMappingContext.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MappingPriority_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/GameplayEffect/Components/GEComp_GrantInputMappingContext.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingToApply;
	static void NewProp_bForceImmediately_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceImmediately;
	static void NewProp_bRequireInputRemapping_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireInputRemapping;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MappingPriority;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGEComp_GrantInputMappingContext>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_InputMappingToApply = { "InputMappingToApply", nullptr, (EPropertyFlags)0x0124080000010011, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGEComp_GrantInputMappingContext, InputMappingToApply), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMappingToApply_MetaData), NewProp_InputMappingToApply_MetaData) };
void Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_bForceImmediately_SetBit(void* Obj)
{
	((UGEComp_GrantInputMappingContext*)Obj)->bForceImmediately = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_bForceImmediately = { "bForceImmediately", nullptr, (EPropertyFlags)0x0020080000010011, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGEComp_GrantInputMappingContext), &Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_bForceImmediately_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bForceImmediately_MetaData), NewProp_bForceImmediately_MetaData) };
void Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_bRequireInputRemapping_SetBit(void* Obj)
{
	((UGEComp_GrantInputMappingContext*)Obj)->bRequireInputRemapping = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_bRequireInputRemapping = { "bRequireInputRemapping", nullptr, (EPropertyFlags)0x0020080000010011, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGEComp_GrantInputMappingContext), &Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_bRequireInputRemapping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireInputRemapping_MetaData), NewProp_bRequireInputRemapping_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_MappingPriority = { "MappingPriority", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGEComp_GrantInputMappingContext, MappingPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MappingPriority_MetaData), NewProp_MappingPriority_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_InputMappingToApply,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_bForceImmediately,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_bRequireInputRemapping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::NewProp_MappingPriority,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayEffectComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::ClassParams = {
	&UGEComp_GrantInputMappingContext::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::PropPointers),
	0,
	0x003130A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::Class_MetaDataParams), Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGEComp_GrantInputMappingContext()
{
	if (!Z_Registration_Info_UClass_UGEComp_GrantInputMappingContext.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGEComp_GrantInputMappingContext.OuterSingleton, Z_Construct_UClass_UGEComp_GrantInputMappingContext_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGEComp_GrantInputMappingContext.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<UGEComp_GrantInputMappingContext>()
{
	return UGEComp_GrantInputMappingContext::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGEComp_GrantInputMappingContext);
UGEComp_GrantInputMappingContext::~UGEComp_GrantInputMappingContext() {}
// End Class UGEComp_GrantInputMappingContext

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GrantInputMappingContext_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGEComp_GrantInputMappingContext, UGEComp_GrantInputMappingContext::StaticClass, TEXT("UGEComp_GrantInputMappingContext"), &Z_Registration_Info_UClass_UGEComp_GrantInputMappingContext, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGEComp_GrantInputMappingContext), 1216235874U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GrantInputMappingContext_h_3977846397(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GrantInputMappingContext_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GrantInputMappingContext_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
