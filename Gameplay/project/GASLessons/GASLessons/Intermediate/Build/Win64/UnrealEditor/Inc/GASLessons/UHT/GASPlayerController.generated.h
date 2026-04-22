// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Controllers/GASPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GASLESSONS_GASPlayerController_generated_h
#error "GASPlayerController.generated.h already included, missing '#pragma once' in GASPlayerController.h"
#endif
#define GASLESSONS_GASPlayerController_generated_h

#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASPlayerController_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGASPlayerController(); \
	friend struct Z_Construct_UClass_AGASPlayerController_Statics; \
public: \
	DECLARE_CLASS(AGASPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GASLessons"), NO_API) \
	DECLARE_SERIALIZER(AGASPlayerController) \
	virtual UObject* _getUObject() const override { return const_cast<AGASPlayerController*>(this); }


#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASPlayerController_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGASPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGASPlayerController(AGASPlayerController&&); \
	AGASPlayerController(const AGASPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGASPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGASPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGASPlayerController) \
	NO_API virtual ~AGASPlayerController();


#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASPlayerController_h_14_PROLOG
#define FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASPlayerController_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASPlayerController_h_17_INCLASS_NO_PURE_DECLS \
	FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASPlayerController_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GASLESSONS_API UClass* StaticClass<class AGASPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Progetti_DBGA_GASLessons_Source_GASLessons_Public_Controllers_GASPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
