// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SpaceShooterCharacter.h"

#ifdef SPACESHOOTER_SpaceShooterCharacter_generated_h
#error "SpaceShooterCharacter.generated.h already included, missing '#pragma once' in SpaceShooterCharacter.h"
#endif
#define SPACESHOOTER_SpaceShooterCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ASpaceShooterCharacter ***************************************************
#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoLook); \
	DECLARE_FUNCTION(execDoMove);


SPACESHOOTER_API UClass* Z_Construct_UClass_ASpaceShooterCharacter_NoRegister();

#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpaceShooterCharacter(); \
	friend struct Z_Construct_UClass_ASpaceShooterCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SPACESHOOTER_API UClass* Z_Construct_UClass_ASpaceShooterCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(ASpaceShooterCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceShooter"), Z_Construct_UClass_ASpaceShooterCharacter_NoRegister) \
	DECLARE_SERIALIZER(ASpaceShooterCharacter)


#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ASpaceShooterCharacter(ASpaceShooterCharacter&&) = delete; \
	ASpaceShooterCharacter(const ASpaceShooterCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpaceShooterCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpaceShooterCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ASpaceShooterCharacter) \
	NO_API virtual ~ASpaceShooterCharacter();


#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterCharacter_h_21_PROLOG
#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ASpaceShooterCharacter;

// ********** End Class ASpaceShooterCharacter *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
