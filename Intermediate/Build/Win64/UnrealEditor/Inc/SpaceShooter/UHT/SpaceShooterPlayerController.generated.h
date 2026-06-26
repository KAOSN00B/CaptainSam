// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SpaceShooterPlayerController.h"

#ifdef SPACESHOOTER_SpaceShooterPlayerController_generated_h
#error "SpaceShooterPlayerController.generated.h already included, missing '#pragma once' in SpaceShooterPlayerController.h"
#endif
#define SPACESHOOTER_SpaceShooterPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ASpaceShooterPlayerController ********************************************
SPACESHOOTER_API UClass* Z_Construct_UClass_ASpaceShooterPlayerController_NoRegister();

#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterPlayerController_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpaceShooterPlayerController(); \
	friend struct Z_Construct_UClass_ASpaceShooterPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SPACESHOOTER_API UClass* Z_Construct_UClass_ASpaceShooterPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(ASpaceShooterPlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceShooter"), Z_Construct_UClass_ASpaceShooterPlayerController_NoRegister) \
	DECLARE_SERIALIZER(ASpaceShooterPlayerController)


#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterPlayerController_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpaceShooterPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ASpaceShooterPlayerController(ASpaceShooterPlayerController&&) = delete; \
	ASpaceShooterPlayerController(const ASpaceShooterPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpaceShooterPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpaceShooterPlayerController); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpaceShooterPlayerController) \
	NO_API virtual ~ASpaceShooterPlayerController();


#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterPlayerController_h_16_PROLOG
#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterPlayerController_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterPlayerController_h_19_INCLASS_NO_PURE_DECLS \
	FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterPlayerController_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ASpaceShooterPlayerController;

// ********** End Class ASpaceShooterPlayerController **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
