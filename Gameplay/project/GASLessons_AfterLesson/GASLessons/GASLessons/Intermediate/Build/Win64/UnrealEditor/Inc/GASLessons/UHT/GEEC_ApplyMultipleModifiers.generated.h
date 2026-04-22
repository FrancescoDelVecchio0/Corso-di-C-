// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameplayEffect/ExecutionCalculations/GEEC_ApplyMultipleModifiers.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GASLESSONS_GEEC_ApplyMultipleModifiers_generated_h
#error "GEEC_ApplyMultipleModifiers.generated.h already included, missing '#pragma once' in GEEC_ApplyMultipleModifiers.h"
#endif
#define GASLESSONS_GEEC_ApplyMultipleModifiers_generated_h

#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGEEC_ApplyMultipleModifiers(); \
	friend struct Z_Construct_UClass_UGEEC_ApplyMultipleModifiers_Statics; \
public: \
	DECLARE_CLASS(UGEEC_ApplyMultipleModifiers, UGameplayEffectExecutionCalculation, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/GASLessons"), NO_API) \
	DECLARE_SERIALIZER(UGEEC_ApplyMultipleModifiers)


#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGEEC_ApplyMultipleModifiers(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UGEEC_ApplyMultipleModifiers(UGEEC_ApplyMultipleModifiers&&); \
	UGEEC_ApplyMultipleModifiers(const UGEEC_ApplyMultipleModifiers&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGEEC_ApplyMultipleModifiers); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGEEC_ApplyMultipleModifiers); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGEEC_ApplyMultipleModifiers) \
	NO_API virtual ~UGEEC_ApplyMultipleModifiers();


#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_22_PROLOG
#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_25_INCLASS_NO_PURE_DECLS \
	FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GASLESSONS_API UClass* StaticClass<class UGEEC_ApplyMultipleModifiers>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_ExecutionCalculations_GEEC_ApplyMultipleModifiers_h


#define FOREACH_ENUM_ECLAMPTYPE(op) \
	op(EClampType::None) \
	op(EClampType::ClampMin) \
	op(EClampType::ClampMax) \
	op(EClampType::ClampRange) 

enum class EClampType : uint8;
template<> struct TIsUEnumClass<EClampType> { enum { Value = true }; };
template<> GASLESSONS_API UEnum* StaticEnum<EClampType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
