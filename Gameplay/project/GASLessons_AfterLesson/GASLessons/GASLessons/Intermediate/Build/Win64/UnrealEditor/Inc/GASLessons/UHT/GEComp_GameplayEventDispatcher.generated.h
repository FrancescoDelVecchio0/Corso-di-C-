// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameplayEffect/Components/GEComp_GameplayEventDispatcher.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GASLESSONS_GEComp_GameplayEventDispatcher_generated_h
#error "GEComp_GameplayEventDispatcher.generated.h already included, missing '#pragma once' in GEComp_GameplayEventDispatcher.h"
#endif
#define GASLESSONS_GEComp_GameplayEventDispatcher_generated_h

#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGEComp_GameplayEventDispatcher(); \
	friend struct Z_Construct_UClass_UGEComp_GameplayEventDispatcher_Statics; \
public: \
	DECLARE_CLASS(UGEComp_GameplayEventDispatcher, UGameplayEffectComponent, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/GASLessons"), NO_API) \
	DECLARE_SERIALIZER(UGEComp_GameplayEventDispatcher)


#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGEComp_GameplayEventDispatcher(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UGEComp_GameplayEventDispatcher(UGEComp_GameplayEventDispatcher&&); \
	UGEComp_GameplayEventDispatcher(const UGEComp_GameplayEventDispatcher&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGEComp_GameplayEventDispatcher); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGEComp_GameplayEventDispatcher); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(UGEComp_GameplayEventDispatcher) \
	NO_API virtual ~UGEComp_GameplayEventDispatcher();


#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_26_PROLOG
#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_29_INCLASS_NO_PURE_DECLS \
	FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GASLESSONS_API UClass* StaticClass<class UGEComp_GameplayEventDispatcher>();

#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_41_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGEComp_GameplayEventDispatcherSimpleTag(); \
	friend struct Z_Construct_UClass_UGEComp_GameplayEventDispatcherSimpleTag_Statics; \
public: \
	DECLARE_CLASS(UGEComp_GameplayEventDispatcherSimpleTag, UGEComp_GameplayEventDispatcher, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GASLessons"), NO_API) \
	DECLARE_SERIALIZER(UGEComp_GameplayEventDispatcherSimpleTag)


#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_41_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGEComp_GameplayEventDispatcherSimpleTag(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UGEComp_GameplayEventDispatcherSimpleTag(UGEComp_GameplayEventDispatcherSimpleTag&&); \
	UGEComp_GameplayEventDispatcherSimpleTag(const UGEComp_GameplayEventDispatcherSimpleTag&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGEComp_GameplayEventDispatcherSimpleTag); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGEComp_GameplayEventDispatcherSimpleTag); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGEComp_GameplayEventDispatcherSimpleTag) \
	NO_API virtual ~UGEComp_GameplayEventDispatcherSimpleTag();


#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_38_PROLOG
#define FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_41_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_41_INCLASS_NO_PURE_DECLS \
	FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h_41_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GASLESSONS_API UClass* StaticClass<class UGEComp_GameplayEventDispatcherSimpleTag>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_dbga_149_Desktop_GASLessons_GASLessons_Source_GASLessons_Public_GameplayEffect_Components_GEComp_GameplayEventDispatcher_h


#define FOREACH_ENUM_EEVENTTARGETTYPE(op) \
	op(EEventTargetType::Source) \
	op(EEventTargetType::Target) \
	op(EEventTargetType::Both) 

enum class EEventTargetType : uint8;
template<> struct TIsUEnumClass<EEventTargetType> { enum { Value = true }; };
template<> GASLESSONS_API UEnum* StaticEnum<EEventTargetType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
