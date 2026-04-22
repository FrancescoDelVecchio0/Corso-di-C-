// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/Components/GASAbilitySystemComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGASAbilitySystemComponent() {}

// Begin Cross Module References
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent();
GASLESSONS_API UClass* Z_Construct_UClass_UGASAbilitySystemComponent();
GASLESSONS_API UClass* Z_Construct_UClass_UGASAbilitySystemComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Class UGASAbilitySystemComponent
void UGASAbilitySystemComponent::StaticRegisterNativesUGASAbilitySystemComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGASAbilitySystemComponent);
UClass* Z_Construct_UClass_UGASAbilitySystemComponent_NoRegister()
{
	return UGASAbilitySystemComponent::StaticClass();
}
struct Z_Construct_UClass_UGASAbilitySystemComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "HideCategories", "Object LOD Lighting Transform Sockets TextureStreaming Object LOD Lighting Transform Sockets TextureStreaming" },
		{ "IncludePath", "Components/GASAbilitySystemComponent.h" },
		{ "ModuleRelativePath", "Public/Components/GASAbilitySystemComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGASAbilitySystemComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UGASAbilitySystemComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilitySystemComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGASAbilitySystemComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGASAbilitySystemComponent_Statics::ClassParams = {
	&UGASAbilitySystemComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGASAbilitySystemComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UGASAbilitySystemComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGASAbilitySystemComponent()
{
	if (!Z_Registration_Info_UClass_UGASAbilitySystemComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGASAbilitySystemComponent.OuterSingleton, Z_Construct_UClass_UGASAbilitySystemComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGASAbilitySystemComponent.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<UGASAbilitySystemComponent>()
{
	return UGASAbilitySystemComponent::StaticClass();
}
UGASAbilitySystemComponent::UGASAbilitySystemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGASAbilitySystemComponent);
UGASAbilitySystemComponent::~UGASAbilitySystemComponent() {}
// End Class UGASAbilitySystemComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Components_GASAbilitySystemComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGASAbilitySystemComponent, UGASAbilitySystemComponent::StaticClass, TEXT("UGASAbilitySystemComponent"), &Z_Registration_Info_UClass_UGASAbilitySystemComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGASAbilitySystemComponent), 2890464380U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Components_GASAbilitySystemComponent_h_315525989(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Components_GASAbilitySystemComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Components_GASAbilitySystemComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
