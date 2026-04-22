// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Abilities/AbilityTasks/AbilityTask_WaitForCharacterLanding.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAbilityTask_WaitForCharacterLanding;
class UGameplayAbility;
struct FHitResult;
#ifdef GASLESSONS_AbilityTask_WaitForCharacterLanding_generated_h
#error "AbilityTask_WaitForCharacterLanding.generated.h already included, missing '#pragma once' in AbilityTask_WaitForCharacterLanding.h"
#endif
#define GASLESSONS_AbilityTask_WaitForCharacterLanding_generated_h

#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_11_DELEGATE \
GASLESSONS_API void FWaitForLandingDelegate_DelegateWrapper(const FMulticastScriptDelegate& WaitForLandingDelegate, FHitResult const& Hit);


#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnLand); \
	DECLARE_FUNCTION(execWaitForCharacterLanding);


#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAbilityTask_WaitForCharacterLanding(); \
	friend struct Z_Construct_UClass_UAbilityTask_WaitForCharacterLanding_Statics; \
public: \
	DECLARE_CLASS(UAbilityTask_WaitForCharacterLanding, UAbilityTask, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GASLessons"), NO_API) \
	DECLARE_SERIALIZER(UAbilityTask_WaitForCharacterLanding)


#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAbilityTask_WaitForCharacterLanding(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UAbilityTask_WaitForCharacterLanding(UAbilityTask_WaitForCharacterLanding&&); \
	UAbilityTask_WaitForCharacterLanding(const UAbilityTask_WaitForCharacterLanding&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAbilityTask_WaitForCharacterLanding); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAbilityTask_WaitForCharacterLanding); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAbilityTask_WaitForCharacterLanding) \
	NO_API virtual ~UAbilityTask_WaitForCharacterLanding();


#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_16_PROLOG
#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_19_INCLASS_NO_PURE_DECLS \
	FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GASLESSONS_API UClass* StaticClass<class UAbilityTask_WaitForCharacterLanding>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_Abilities_AbilityTasks_AbilityTask_WaitForCharacterLanding_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
