// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AttributeSets/CharacterAttributeSet.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "Net/Core/PushModel/PushModelMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayAttributeData;
#ifdef GASLESSONS_CharacterAttributeSet_generated_h
#error "CharacterAttributeSet.generated.h already included, missing '#pragma once' in CharacterAttributeSet.h"
#endif
#define GASLESSONS_CharacterAttributeSet_generated_h

#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_CharacterAttributeSet_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_HealthMax); \
	DECLARE_FUNCTION(execOnRep_Health);


#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_CharacterAttributeSet_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCharacterAttributeSet(); \
	friend struct Z_Construct_UClass_UCharacterAttributeSet_Statics; \
public: \
	DECLARE_CLASS(UCharacterAttributeSet, UGASAttributeSet, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GASLessons"), NO_API) \
	DECLARE_SERIALIZER(UCharacterAttributeSet) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Health=NETFIELD_REP_START, \
		HealthMax, \
		NETFIELD_REP_END=HealthMax	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override; \
private: \
	REPLICATED_BASE_CLASS(UCharacterAttributeSet) \
public:


#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_CharacterAttributeSet_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCharacterAttributeSet(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCharacterAttributeSet(UCharacterAttributeSet&&); \
	UCharacterAttributeSet(const UCharacterAttributeSet&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCharacterAttributeSet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCharacterAttributeSet); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCharacterAttributeSet) \
	NO_API virtual ~UCharacterAttributeSet();


#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_CharacterAttributeSet_h_13_PROLOG
#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_CharacterAttributeSet_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_CharacterAttributeSet_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_CharacterAttributeSet_h_16_INCLASS_NO_PURE_DECLS \
	FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_CharacterAttributeSet_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GASLESSONS_API UClass* StaticClass<class UCharacterAttributeSet>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_AttributeSets_CharacterAttributeSet_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
