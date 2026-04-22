// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/GameplayEffect/Components/GEComp_GameplayEventDispatcher.h"
#include "GameplayAbilities/Public/AttributeSet.h"
#include "GameplayAbilities/Public/GameplayEffect.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGEComp_GameplayEventDispatcher() {}

// Begin Cross Module References
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffectComponent();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAttribute();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GASLESSONS_API UClass* Z_Construct_UClass_UGEComp_GameplayEventDispatcher();
GASLESSONS_API UClass* Z_Construct_UClass_UGEComp_GameplayEventDispatcher_NoRegister();
GASLESSONS_API UClass* Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag();
GASLESSONS_API UClass* Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_NoRegister();
GASLESSONS_API UEnum* Z_Construct_UEnum_GASLessons_EEventTargetType();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Enum EEventTargetType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEventTargetType;
static UEnum* EEventTargetType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EEventTargetType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EEventTargetType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GASLessons_EEventTargetType, (UObject*)Z_Construct_UPackage__Script_GASLessons(), TEXT("EEventTargetType"));
	}
	return Z_Registration_Info_UEnum_EEventTargetType.OuterSingleton;
}
template<> GASLESSONS_API UEnum* StaticEnum<EEventTargetType>()
{
	return EEventTargetType_StaticEnum();
}
struct Z_Construct_UEnum_GASLessons_EEventTargetType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Both.Comment", "/**Event will be sent both to the Source and the Target of the Gameplay Effect*/" },
		{ "Both.Name", "EEventTargetType::Both" },
		{ "Both.ToolTip", "Event will be sent both to the Source and the Target of the Gameplay Effect" },
		{ "ModuleRelativePath", "Public/GameplayEffect/Components/GEComp_GameplayEventDispatcher.h" },
		{ "Source.Comment", "/**Event will be sent only to the Source of the Gameplay Effect, if available*/" },
		{ "Source.Name", "EEventTargetType::Source" },
		{ "Source.ToolTip", "Event will be sent only to the Source of the Gameplay Effect, if available" },
		{ "Target.Comment", "/**Event will be sent only to the Target of the Gameplay Effect*/" },
		{ "Target.Name", "EEventTargetType::Target" },
		{ "Target.ToolTip", "Event will be sent only to the Target of the Gameplay Effect" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EEventTargetType::Source", (int64)EEventTargetType::Source },
		{ "EEventTargetType::Target", (int64)EEventTargetType::Target },
		{ "EEventTargetType::Both", (int64)EEventTargetType::Both },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GASLessons_EEventTargetType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GASLessons,
	nullptr,
	"EEventTargetType",
	"EEventTargetType",
	Z_Construct_UEnum_GASLessons_EEventTargetType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GASLessons_EEventTargetType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GASLessons_EEventTargetType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GASLessons_EEventTargetType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GASLessons_EEventTargetType()
{
	if (!Z_Registration_Info_UEnum_EEventTargetType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEventTargetType.InnerSingleton, Z_Construct_UEnum_GASLessons_EEventTargetType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EEventTargetType.InnerSingleton;
}
// End Enum EEventTargetType

// Begin Class UGEComp_GameplayEventDispatcher
void UGEComp_GameplayEventDispatcher::StaticRegisterNativesUGEComp_GameplayEventDispatcher()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGEComp_GameplayEventDispatcher);
UClass* Z_Construct_UClass_UGEComp_GameplayEventDispatcher_NoRegister()
{
	return UGEComp_GameplayEventDispatcher::StaticClass();
}
struct Z_Construct_UClass_UGEComp_GameplayEventDispatcher_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GameplayEffect/Components/GEComp_GameplayEventDispatcher.h" },
		{ "ModuleRelativePath", "Public/GameplayEffect/Components/GEComp_GameplayEventDispatcher.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGEComp_GameplayEventDispatcher>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UGEComp_GameplayEventDispatcher_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayEffectComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGEComp_GameplayEventDispatcher_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGEComp_GameplayEventDispatcher_Statics::ClassParams = {
	&UGEComp_GameplayEventDispatcher::StaticClass,
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
	0x003130A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGEComp_GameplayEventDispatcher_Statics::Class_MetaDataParams), Z_Construct_UClass_UGEComp_GameplayEventDispatcher_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGEComp_GameplayEventDispatcher()
{
	if (!Z_Registration_Info_UClass_UGEComp_GameplayEventDispatcher.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGEComp_GameplayEventDispatcher.OuterSingleton, Z_Construct_UClass_UGEComp_GameplayEventDispatcher_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGEComp_GameplayEventDispatcher.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<UGEComp_GameplayEventDispatcher>()
{
	return UGEComp_GameplayEventDispatcher::StaticClass();
}
UGEComp_GameplayEventDispatcher::UGEComp_GameplayEventDispatcher() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGEComp_GameplayEventDispatcher);
UGEComp_GameplayEventDispatcher::~UGEComp_GameplayEventDispatcher() {}
// End Class UGEComp_GameplayEventDispatcher

// Begin Class UGEComp_GameplayEventDispatcherSimpleTag
void UGEComp_GameplayEventDispatcherSimpleTag::StaticRegisterNativesUGEComp_GameplayEventDispatcherSimpleTag()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGEComp_GameplayEventDispatcherSimpleTag);
UClass* Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_NoRegister()
{
	return UGEComp_GameplayEventDispatcherSimpleTag::StaticClass();
}
struct Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "GameplayEffect/Components/GEComp_GameplayEventDispatcher.h" },
		{ "ModuleRelativePath", "Public/GameplayEffect/Components/GEComp_GameplayEventDispatcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventTag_MetaData[] = {
		{ "Category", "Event" },
		{ "ModuleRelativePath", "Public/GameplayEffect/Components/GEComp_GameplayEventDispatcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetType_MetaData[] = {
		{ "Category", "Event" },
		{ "ModuleRelativePath", "Public/GameplayEffect/Components/GEComp_GameplayEventDispatcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MagnitudeAttribute_MetaData[] = {
		{ "Category", "Event" },
		{ "ModuleRelativePath", "Public/GameplayEffect/Components/GEComp_GameplayEventDispatcher.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTag;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TargetType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TargetType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MagnitudeAttribute;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGEComp_GameplayEventDispatcherSimpleTag>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::NewProp_EventTag = { "EventTag", nullptr, (EPropertyFlags)0x0010000000010011, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGEComp_GameplayEventDispatcherSimpleTag, EventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventTag_MetaData), NewProp_EventTag_MetaData) }; // 1298103297
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::NewProp_TargetType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::NewProp_TargetType = { "TargetType", nullptr, (EPropertyFlags)0x0010000000010011, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGEComp_GameplayEventDispatcherSimpleTag, TargetType), Z_Construct_UEnum_GASLessons_EEventTargetType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetType_MetaData), NewProp_TargetType_MetaData) }; // 2287787651
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::NewProp_MagnitudeAttribute = { "MagnitudeAttribute", nullptr, (EPropertyFlags)0x0010000000010011, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGEComp_GameplayEventDispatcherSimpleTag, MagnitudeAttribute), Z_Construct_UScriptStruct_FGameplayAttribute, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MagnitudeAttribute_MetaData), NewProp_MagnitudeAttribute_MetaData) }; // 2792951819
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::NewProp_EventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::NewProp_TargetType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::NewProp_TargetType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::NewProp_MagnitudeAttribute,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGEComp_GameplayEventDispatcher,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::ClassParams = {
	&UGEComp_GameplayEventDispatcherSimpleTag::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::PropPointers),
	0,
	0x003130A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::Class_MetaDataParams), Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag()
{
	if (!Z_Registration_Info_UClass_UGEComp_GameplayEventDispatcherSimpleTag.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGEComp_GameplayEventDispatcherSimpleTag.OuterSingleton, Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGEComp_GameplayEventDispatcherSimpleTag.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<UGEComp_GameplayEventDispatcherSimpleTag>()
{
	return UGEComp_GameplayEventDispatcherSimpleTag::StaticClass();
}
UGEComp_GameplayEventDispatcherSimpleTag::UGEComp_GameplayEventDispatcherSimpleTag() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGEComp_GameplayEventDispatcherSimpleTag);
UGEComp_GameplayEventDispatcherSimpleTag::~UGEComp_GameplayEventDispatcherSimpleTag() {}
// End Class UGEComp_GameplayEventDispatcherSimpleTag

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EEventTargetType_StaticEnum, TEXT("EEventTargetType"), &Z_Registration_Info_UEnum_EEventTargetType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2287787651U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGEComp_GameplayEventDispatcher, UGEComp_GameplayEventDispatcher::StaticClass, TEXT("UGEComp_GameplayEventDispatcher"), &Z_Registration_Info_UClass_UGEComp_GameplayEventDispatcher, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGEComp_GameplayEventDispatcher), 1349330235U) },
		{ Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag, UGEComp_GameplayEventDispatcherSimpleTag::StaticClass, TEXT("UGEComp_GameplayEventDispatcherSimpleTag"), &Z_Registration_Info_UClass_UGEComp_GameplayEventDispatcherSimpleTag, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGEComp_GameplayEventDispatcherSimpleTag), 3677672909U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_3855345769(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
