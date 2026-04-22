// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/GASCharacter.h"
#include "GameplayAbilities/Public/GameplayCueInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGASCharacter() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility_NoRegister();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayCueTag();
GASLESSONS_API UClass* Z_Construct_UClass_AGASCharacter();
GASLESSONS_API UClass* Z_Construct_UClass_AGASCharacter_NoRegister();
GASLESSONS_API UClass* Z_Construct_UClass_AGASLessonsCharacter();
GASLESSONS_API UClass* Z_Construct_UClass_UGASAbilitySystemComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Class AGASCharacter
void AGASCharacter::StaticRegisterNativesAGASCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGASCharacter);
UClass* Z_Construct_UClass_AGASCharacter_NoRegister()
{
	return AGASCharacter::StaticClass();
}
struct Z_Construct_UClass_AGASCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "GASCharacter.h" },
		{ "ModuleRelativePath", "Public/GASCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySystemComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//@GAS_INTERFACE - Ability System Component Property (already using an inherited version in order to allow overrides via code)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GASCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@GAS_INTERFACE - Ability System Component Property (already using an inherited version in order to allow overrides via code)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Example_CueTag_MetaData[] = {
		{ "Category", "GASCharacter" },
		{ "ModuleRelativePath", "Public/GASCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Example_GAClass_MetaData[] = {
		{ "Category", "GASCharacter" },
		{ "ModuleRelativePath", "Public/GASCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilitySystemComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Example_CueTag;
	static const UECodeGen_Private::FClassPropertyParams NewProp_Example_GAClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGASCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGASCharacter_Statics::NewProp_AbilitySystemComponent = { "AbilitySystemComponent", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGASCharacter, AbilitySystemComponent), Z_Construct_UClass_UGASAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySystemComponent_MetaData), NewProp_AbilitySystemComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGASCharacter_Statics::NewProp_Example_CueTag = { "Example_CueTag", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGASCharacter, Example_CueTag), Z_Construct_UScriptStruct_FGameplayCueTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Example_CueTag_MetaData), NewProp_Example_CueTag_MetaData) }; // 485800147
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AGASCharacter_Statics::NewProp_Example_GAClass = { "Example_GAClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGASCharacter, Example_GAClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Example_GAClass_MetaData), NewProp_Example_GAClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGASCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGASCharacter_Statics::NewProp_AbilitySystemComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGASCharacter_Statics::NewProp_Example_CueTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGASCharacter_Statics::NewProp_Example_GAClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGASCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGASCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGASLessonsCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGASCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AGASCharacter_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(AGASCharacter, IAbilitySystemInterface), false },  // 2272790346
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGASCharacter_Statics::ClassParams = {
	&AGASCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AGASCharacter_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AGASCharacter_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGASCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AGASCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGASCharacter()
{
	if (!Z_Registration_Info_UClass_AGASCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGASCharacter.OuterSingleton, Z_Construct_UClass_AGASCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGASCharacter.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<AGASCharacter>()
{
	return AGASCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGASCharacter);
AGASCharacter::~AGASCharacter() {}
// End Class AGASCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_GASCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGASCharacter, AGASCharacter::StaticClass, TEXT("AGASCharacter"), &Z_Registration_Info_UClass_AGASCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGASCharacter), 1994477728U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_GASCharacter_h_3122915566(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_GASCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_GASCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
