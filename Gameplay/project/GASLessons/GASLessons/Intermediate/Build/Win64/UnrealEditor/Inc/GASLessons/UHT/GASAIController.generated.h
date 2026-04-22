// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Controllers/GASAIController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GASLESSONS_GASAIController_generated_h
#error "GASAIController.generated.h already included, missing '#pragma once' in GASAIController.h"
#endif
#define GASLESSONS_GASAIController_generated_h

#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASAIController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGASAIController(); \
	friend struct Z_Construct_UClass_AGASAIController_Statics; \
public: \
	DECLARE_CLASS(AGASAIController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GASLessons"), NO_API) \
	DECLARE_SERIALIZER(AGASAIController) \
	virtual UObject* _getUObject() const override { return const_cast<AGASAIController*>(this); }


#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASAIController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGASAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGASAIController(AGASAIController&&); \
	AGASAIController(const AGASAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGASAIController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGASAIController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGASAIController) \
	NO_API virtual ~AGASAIController();


#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASAIController_h_12_PROLOG
#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASAIController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASAIController_h_15_INCLASS_NO_PURE_DECLS \
	FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASAIController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GASLESSONS_API UClass* StaticClass<class AGASAIController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
