// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h"
#include "GameplayAbilities/Public/AttributeSet.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGEEC_ApplyMultipleModifiers() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffectExecutionCalculation();
GAMEPLAYABILITIES_API UEnum* Z_Construct_UEnum_GameplayAbilities_EGameplayModOp();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAttribute();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GASLESSONS_API UClass* Z_Construct_UClass_UGEEC_ApplyMultipleModifiers();
GASLESSONS_API UClass* Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_NoRegister();
GASLESSONS_API UEnum* Z_Construct_UEnum_GASLessons_EClampType();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Enum EClampType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EClampType;
static UEnum* EClampType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EClampType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EClampType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GASLessons_EClampType, (UObject*)Z_Construct_UPackage__Script_GASLessons(), TEXT("EClampType"));
	}
	return Z_Registration_Info_UEnum_EClampType.OuterSingleton;
}
template<> GASLESSONS_API UEnum* StaticEnum<EClampType>()
{
	return EClampType_StaticEnum();
}
struct Z_Construct_UEnum_GASLessons_EClampType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ClampMax.Name", "EClampType::ClampMax" },
		{ "ClampMin.Name", "EClampType::ClampMin" },
		{ "ClampRange.Name", "EClampType::ClampRange" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h" },
		{ "None.Name", "EClampType::None" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EClampType::None", (int64)EClampType::None },
		{ "EClampType::ClampMin", (int64)EClampType::ClampMin },
		{ "EClampType::ClampMax", (int64)EClampType::ClampMax },
		{ "EClampType::ClampRange", (int64)EClampType::ClampRange },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GASLessons_EClampType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GASLessons,
	nullptr,
	"EClampType",
	"EClampType",
	Z_Construct_UEnum_GASLessons_EClampType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GASLessons_EClampType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GASLessons_EClampType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GASLessons_EClampType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GASLessons_EClampType()
{
	if (!Z_Registration_Info_UEnum_EClampType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EClampType.InnerSingleton, Z_Construct_UEnum_GASLessons_EClampType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EClampType.InnerSingleton;
}
// End Enum EClampType

// Begin Class UGEEC_ApplyMultipleModifiers
void UGEEC_ApplyMultipleModifiers::StaticRegisterNativesUGEEC_ApplyMultipleModifiers()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGEEC_ApplyMultipleModifiers);
UClass* Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_NoRegister()
{
	return UGEEC_ApplyMultipleModifiers::StaticClass();
}
struct Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "DisplayName", "Apply Multiple Modifiers" },
		{ "IncludePath", "GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemporaryAggregatorTag_MetaData[] = {
		{ "Category", "GEEC_ApplyMultipleModifiers" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attribute_MetaData[] = {
		{ "Category", "GEEC_ApplyMultipleModifiers" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModifierOp_MetaData[] = {
		{ "Category", "GEEC_ApplyMultipleModifiers" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClampPolicy_MetaData[] = {
		{ "Category", "GEEC_ApplyMultipleModifiers" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClampValue_MetaData[] = {
		{ "Category", "GEEC_ApplyMultipleModifiers" },
		{ "EditCondition", "ClampPolicy != EClampType::ClampRange" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClampRangeValues_MetaData[] = {
		{ "Category", "GEEC_ApplyMultipleModifiers" },
		{ "EditCondition", "ClampPolicy == EClampType::ClampRange" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h" },
		{ "XAxisName", "Min" },
		{ "YAxisName", "Max" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TemporaryAggregatorTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Attribute;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ModifierOp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ClampPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ClampPolicy;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ClampValue;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClampRangeValues;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGEEC_ApplyMultipleModifiers>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_TemporaryAggregatorTag = { "TemporaryAggregatorTag", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGEEC_ApplyMultipleModifiers, TemporaryAggregatorTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemporaryAggregatorTag_MetaData), NewProp_TemporaryAggregatorTag_MetaData) }; // 1298103297
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGEEC_ApplyMultipleModifiers, Attribute), Z_Construct_UScriptStruct_FGameplayAttribute, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attribute_MetaData), NewProp_Attribute_MetaData) }; // 2792951819
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_ModifierOp = { "ModifierOp", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGEEC_ApplyMultipleModifiers, ModifierOp), Z_Construct_UEnum_GameplayAbilities_EGameplayModOp, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModifierOp_MetaData), NewProp_ModifierOp_MetaData) }; // 2039796046
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_ClampPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_ClampPolicy = { "ClampPolicy", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGEEC_ApplyMultipleModifiers, ClampPolicy), Z_Construct_UEnum_GASLessons_EClampType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClampPolicy_MetaData), NewProp_ClampPolicy_MetaData) }; // 642130422
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_ClampValue = { "ClampValue", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGEEC_ApplyMultipleModifiers, ClampValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClampValue_MetaData), NewProp_ClampValue_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_ClampRangeValues = { "ClampRangeValues", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGEEC_ApplyMultipleModifiers, ClampRangeValues), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClampRangeValues_MetaData), NewProp_ClampRangeValues_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_TemporaryAggregatorTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_Attribute,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_ModifierOp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_ClampPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_ClampPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_ClampValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::NewProp_ClampRangeValues,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayEffectExecutionCalculation,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::ClassParams = {
	&UGEEC_ApplyMultipleModifiers::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::PropPointers),
	0,
	0x001000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::Class_MetaDataParams), Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGEEC_ApplyMultipleModifiers()
{
	if (!Z_Registration_Info_UClass_UGEEC_ApplyMultipleModifiers.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGEEC_ApplyMultipleModifiers.OuterSingleton, Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGEEC_ApplyMultipleModifiers.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<UGEEC_ApplyMultipleModifiers>()
{
	return UGEEC_ApplyMultipleModifiers::StaticClass();
}
UGEEC_ApplyMultipleModifiers::UGEEC_ApplyMultipleModifiers(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGEEC_ApplyMultipleModifiers);
UGEEC_ApplyMultipleModifiers::~UGEEC_ApplyMultipleModifiers() {}
// End Class UGEEC_ApplyMultipleModifiers

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EClampType_StaticEnum, TEXT("EClampType"), &Z_Registration_Info_UEnum_EClampType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 642130422U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGEEC_ApplyMultipleModifiers, UGEEC_ApplyMultipleModifiers::StaticClass, TEXT("UGEEC_ApplyMultipleModifiers"), &Z_Registration_Info_UClass_UGEEC_ApplyMultipleModifiers, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGEEC_ApplyMultipleModifiers), 1181529903U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_1356967980(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
