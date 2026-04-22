// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GASLessons/Public/Abilities/AbilityTasks/AbilityTask_WaitForCharacterLanding.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAbilityTask_WaitForCharacterLanding() {}

// Begin Cross Module References
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilityTask();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility_NoRegister();
GASLESSONS_API UClass* Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding();
GASLESSONS_API UClass* Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_NoRegister();
GASLESSONS_API UFunction* Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_GASLessons();
// End Cross Module References

// Begin Delegate FWaitForLandingDelegate
struct Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics
{
	struct _Script_GASLessons_eventWaitForLandingDelegate_Parms
	{
		FHitResult Hit;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Abilities/AbilityTasks/AbilityTask_WaitForCharacterLanding.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GASLessons_eventWaitForLandingDelegate_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::NewProp_Hit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_GASLessons, nullptr, "WaitForLandingDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::_Script_GASLessons_eventWaitForLandingDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::_Script_GASLessons_eventWaitForLandingDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FWaitForLandingDelegate_DelegateWrapper(const FMulticastScriptDelegate& WaitForLandingDelegate, FHitResult const& Hit)
{
	struct _Script_GASLessons_eventWaitForLandingDelegate_Parms
	{
		FHitResult Hit;
	};
	_Script_GASLessons_eventWaitForLandingDelegate_Parms Parms;
	Parms.Hit=Hit;
	WaitForLandingDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FWaitForLandingDelegate

// Begin Class UAbilityTask_WaitForCharacterLanding Function OnLand
struct Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics
{
	struct AbilityTask_WaitForCharacterLanding_eventOnLand_Parms
	{
		FHitResult HitResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Abilities/AbilityTasks/AbilityTask_WaitForCharacterLanding.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_WaitForCharacterLanding_eventOnLand_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitResult_MetaData), NewProp_HitResult_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::NewProp_HitResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding, nullptr, "OnLand", nullptr, nullptr, Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::AbilityTask_WaitForCharacterLanding_eventOnLand_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::AbilityTask_WaitForCharacterLanding_eventOnLand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAbilityTask_WaitForCharacterLanding::execOnLand)
{
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnLand(Z_Param_Out_HitResult);
	P_NATIVE_END;
}
// End Class UAbilityTask_WaitForCharacterLanding Function OnLand

// Begin Class UAbilityTask_WaitForCharacterLanding Function WaitForCharacterLanding
struct Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics
{
	struct AbilityTask_WaitForCharacterLanding_eventWaitForCharacterLanding_Parms
	{
		UGameplayAbility* OwningAbility;
		bool bCheckAlreadyOnGround;
		UAbilityTask_WaitForCharacterLanding* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "TRUE" },
		{ "Category", "Ability|Tasks" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Wait until the specified gameplay tag event is triggered. By default this will look at the owner of this ability. OptionalExternalTarget can be set to make this look at another actor's tags for changes\n\x09* It will keep listening as long as OnlyTriggerOnce = false\n\x09* If OnlyMatchExact = false it will trigger for nested tags\n\x09*/" },
#endif
		{ "CPP_Default_bCheckAlreadyOnGround", "true" },
		{ "DefaultToSelf", "OwningAbility" },
		{ "HidePin", "OwningAbility" },
		{ "ModuleRelativePath", "Public/Abilities/AbilityTasks/AbilityTask_WaitForCharacterLanding.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Wait until the specified gameplay tag event is triggered. By default this will look at the owner of this ability. OptionalExternalTarget can be set to make this look at another actor's tags for changes\nIt will keep listening as long as OnlyTriggerOnce = false\nIf OnlyMatchExact = false it will trigger for nested tags" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwningAbility;
	static void NewProp_bCheckAlreadyOnGround_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCheckAlreadyOnGround;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::NewProp_OwningAbility = { "OwningAbility", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_WaitForCharacterLanding_eventWaitForCharacterLanding_Parms, OwningAbility), Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::NewProp_bCheckAlreadyOnGround_SetBit(void* Obj)
{
	((AbilityTask_WaitForCharacterLanding_eventWaitForCharacterLanding_Parms*)Obj)->bCheckAlreadyOnGround = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::NewProp_bCheckAlreadyOnGround = { "bCheckAlreadyOnGround", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AbilityTask_WaitForCharacterLanding_eventWaitForCharacterLanding_Parms), &Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::NewProp_bCheckAlreadyOnGround_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_WaitForCharacterLanding_eventWaitForCharacterLanding_Parms, ReturnValue), Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::NewProp_OwningAbility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::NewProp_bCheckAlreadyOnGround,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding, nullptr, "WaitForCharacterLanding", nullptr, nullptr, Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::AbilityTask_WaitForCharacterLanding_eventWaitForCharacterLanding_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::AbilityTask_WaitForCharacterLanding_eventWaitForCharacterLanding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAbilityTask_WaitForCharacterLanding::execWaitForCharacterLanding)
{
	P_GET_OBJECT(UGameplayAbility,Z_Param_OwningAbility);
	P_GET_UBOOL(Z_Param_bCheckAlreadyOnGround);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UAbilityTask_WaitForCharacterLanding**)Z_Param__Result=UAbilityTask_WaitForCharacterLanding::WaitForCharacterLanding(Z_Param_OwningAbility,Z_Param_bCheckAlreadyOnGround);
	P_NATIVE_END;
}
// End Class UAbilityTask_WaitForCharacterLanding Function WaitForCharacterLanding

// Begin Class UAbilityTask_WaitForCharacterLanding
void UAbilityTask_WaitForCharacterLanding::StaticRegisterNativesUAbilityTask_WaitForCharacterLanding()
{
	UClass* Class = UAbilityTask_WaitForCharacterLanding::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnLand", &UAbilityTask_WaitForCharacterLanding::execOnLand },
		{ "WaitForCharacterLanding", &UAbilityTask_WaitForCharacterLanding::execWaitForCharacterLanding },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAbilityTask_WaitForCharacterLanding);
UClass* Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_NoRegister()
{
	return UAbilityTask_WaitForCharacterLanding::StaticClass();
}
struct Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Abilities/AbilityTasks/AbilityTask_WaitForCharacterLanding.h" },
		{ "ModuleRelativePath", "Public/Abilities/AbilityTasks/AbilityTask_WaitForCharacterLanding.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterLanded_MetaData[] = {
		{ "ModuleRelativePath", "Public/Abilities/AbilityTasks/AbilityTask_WaitForCharacterLanding.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCheckAlreadyOnGround_MetaData[] = {
		{ "ModuleRelativePath", "Public/Abilities/AbilityTasks/AbilityTask_WaitForCharacterLanding.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterLanded;
	static void NewProp_bCheckAlreadyOnGround_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCheckAlreadyOnGround;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_OnLand, "OnLand" }, // 3485974149
		{ &Z_Construct_UFunction_UAbilityTask_WaitForCharacterLanding_WaitForCharacterLanding, "WaitForCharacterLanding" }, // 4039899324
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAbilityTask_WaitForCharacterLanding>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::NewProp_OnCharacterLanded = { "OnCharacterLanded", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAbilityTask_WaitForCharacterLanding, OnCharacterLanded), Z_Construct_UDelegateFunction_GASLessons_WaitForLandingDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterLanded_MetaData), NewProp_OnCharacterLanded_MetaData) }; // 1061323965
void Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::NewProp_bCheckAlreadyOnGround_SetBit(void* Obj)
{
	((UAbilityTask_WaitForCharacterLanding*)Obj)->bCheckAlreadyOnGround = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::NewProp_bCheckAlreadyOnGround = { "bCheckAlreadyOnGround", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAbilityTask_WaitForCharacterLanding), &Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::NewProp_bCheckAlreadyOnGround_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCheckAlreadyOnGround_MetaData), NewProp_bCheckAlreadyOnGround_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::NewProp_OnCharacterLanded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::NewProp_bCheckAlreadyOnGround,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilityTask,
	(UObject* (*)())Z_Construct_UPackage__Script_GASLessons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::ClassParams = {
	&UAbilityTask_WaitForCharacterLanding::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::Class_MetaDataParams), Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding()
{
	if (!Z_Registration_Info_UClass_UAbilityTask_WaitForCharacterLanding.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAbilityTask_WaitForCharacterLanding.OuterSingleton, Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAbilityTask_WaitForCharacterLanding.OuterSingleton;
}
template<> GASLESSONS_API UClass* StaticClass<UAbilityTask_WaitForCharacterLanding>()
{
	return UAbilityTask_WaitForCharacterLanding::StaticClass();
}
UAbilityTask_WaitForCharacterLanding::UAbilityTask_WaitForCharacterLanding(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAbilityTask_WaitForCharacterLanding);
UAbilityTask_WaitForCharacterLanding::~UAbilityTask_WaitForCharacterLanding() {}
// End Class UAbilityTask_WaitForCharacterLanding

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding, UAbilityTask_WaitForCharacterLanding::StaticClass, TEXT("UAbilityTask_WaitForCharacterLanding"), &Z_Registration_Info_UClass_UAbilityTask_WaitForCharacterLanding, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAbilityTask_WaitForCharacterLanding), 3673783169U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_409885633(TEXT("/Script/GASLessons"),
	Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
