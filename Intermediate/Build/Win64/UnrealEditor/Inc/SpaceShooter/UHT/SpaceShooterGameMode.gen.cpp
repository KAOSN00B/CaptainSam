// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SpaceShooterGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeSpaceShooterGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
SPACESHOOTER_API UClass* Z_Construct_UClass_ASpaceShooterGameMode();
SPACESHOOTER_API UClass* Z_Construct_UClass_ASpaceShooterGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_SpaceShooter();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASpaceShooterGameMode ****************************************************
void ASpaceShooterGameMode::StaticRegisterNativesASpaceShooterGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ASpaceShooterGameMode;
UClass* ASpaceShooterGameMode::GetPrivateStaticClass()
{
	using TClass = ASpaceShooterGameMode;
	if (!Z_Registration_Info_UClass_ASpaceShooterGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("SpaceShooterGameMode"),
			Z_Registration_Info_UClass_ASpaceShooterGameMode.InnerSingleton,
			StaticRegisterNativesASpaceShooterGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ASpaceShooterGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_ASpaceShooterGameMode_NoRegister()
{
	return ASpaceShooterGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASpaceShooterGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a third person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SpaceShooterGameMode.h" },
		{ "ModuleRelativePath", "SpaceShooterGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a third person game" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpaceShooterGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ASpaceShooterGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SpaceShooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpaceShooterGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpaceShooterGameMode_Statics::ClassParams = {
	&ASpaceShooterGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpaceShooterGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpaceShooterGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpaceShooterGameMode()
{
	if (!Z_Registration_Info_UClass_ASpaceShooterGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpaceShooterGameMode.OuterSingleton, Z_Construct_UClass_ASpaceShooterGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpaceShooterGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpaceShooterGameMode);
ASpaceShooterGameMode::~ASpaceShooterGameMode() {}
// ********** End Class ASpaceShooterGameMode ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterGameMode_h__Script_SpaceShooter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpaceShooterGameMode, ASpaceShooterGameMode::StaticClass, TEXT("ASpaceShooterGameMode"), &Z_Registration_Info_UClass_ASpaceShooterGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpaceShooterGameMode), 2229282039U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterGameMode_h__Script_SpaceShooter_2738692583(TEXT("/Script/SpaceShooter"),
	Z_CompiledInDeferFile_FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterGameMode_h__Script_SpaceShooter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_rober_Documents_Unreal_Projects_SpaceShooter_Source_SpaceShooter_SpaceShooterGameMode_h__Script_SpaceShooter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
