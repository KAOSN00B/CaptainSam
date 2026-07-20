// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpaceShooter_init() {}
	SPACESHOOTER_API UFunction* Z_Construct_UDelegateFunction_SpaceShooter_OnEnemyDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SpaceShooter;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SpaceShooter()
	{
		if (!Z_Registration_Info_UPackage__Script_SpaceShooter.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SpaceShooter_OnEnemyDied__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SpaceShooter",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x50D6A142,
				0xFF9EDA70,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SpaceShooter.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SpaceShooter.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SpaceShooter(Z_Construct_UPackage__Script_SpaceShooter, TEXT("/Script/SpaceShooter"), Z_Registration_Info_UPackage__Script_SpaceShooter, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x50D6A142, 0xFF9EDA70));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
