// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Gun.h"

#ifdef SPACESHOOTER_Gun_generated_h
#error "Gun.generated.h already included, missing '#pragma once' in Gun.h"
#endif
#define SPACESHOOTER_Gun_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AGun *********************************************************************
SPACESHOOTER_API UClass* Z_Construct_UClass_AGun_NoRegister();

#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_Gun_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGun(); \
	friend struct Z_Construct_UClass_AGun_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SPACESHOOTER_API UClass* Z_Construct_UClass_AGun_NoRegister(); \
public: \
	DECLARE_CLASS2(AGun, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceShooter"), Z_Construct_UClass_AGun_NoRegister) \
	DECLARE_SERIALIZER(AGun)


#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_Gun_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGun(AGun&&) = delete; \
	AGun(const AGun&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGun); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGun); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGun) \
	NO_API virtual ~AGun();


#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_Gun_h_12_PROLOG
#define FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_Gun_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_Gun_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_Gun_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGun;

// ********** End Class AGun ***********************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_Gun_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
