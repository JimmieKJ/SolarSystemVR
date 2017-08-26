// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "SolarSystemVR.h"
#include "GeneratedCppIncludes.h"
#include "SolarSystemVR.generated.dep.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1SolarSystemVR() {}
	void AMyCharacter::StaticRegisterNativesAMyCharacter()
	{
	}
	IMPLEMENT_CLASS(AMyCharacter, 2343472692);
	void APawnMoveControl::StaticRegisterNativesAPawnMoveControl()
	{
	}
	IMPLEMENT_CLASS(APawnMoveControl, 1552950181);
	void ASocketActor::StaticRegisterNativesASocketActor()
	{
	}
	IMPLEMENT_CLASS(ASocketActor, 324533537);
	void ATCPClient::StaticRegisterNativesATCPClient()
	{
	}
	IMPLEMENT_CLASS(ATCPClient, 3682676565);
	void AMyPlayerController::StaticRegisterNativesAMyPlayerController()
	{
	}
	IMPLEMENT_CLASS(AMyPlayerController, 4040226889);
	void ASolarSystemVRGameModeBase::StaticRegisterNativesASolarSystemVRGameModeBase()
	{
	}
	IMPLEMENT_CLASS(ASolarSystemVRGameModeBase, 3054839605);
	void ATCPConnection::StaticRegisterNativesATCPConnection()
	{
	}
	IMPLEMENT_CLASS(ATCPConnection, 2097466293);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_APlayerController();
	ENGINE_API class UClass* Z_Construct_UClass_AGameModeBase();

	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_AMyCharacter_NoRegister();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_AMyCharacter();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_APawnMoveControl_NoRegister();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_APawnMoveControl();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_ASocketActor_NoRegister();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_ASocketActor();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_ATCPClient_NoRegister();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_ATCPClient();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_AMyPlayerController_NoRegister();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_AMyPlayerController();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_ASolarSystemVRGameModeBase_NoRegister();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_ASolarSystemVRGameModeBase();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_ATCPConnection_NoRegister();
	SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_ATCPConnection();
	SOLARSYSTEMVR_API class UPackage* Z_Construct_UPackage__Script_SolarSystemVR();
	UClass* Z_Construct_UClass_AMyCharacter_NoRegister()
	{
		return AMyCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_AMyCharacter()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ACharacter();
			Z_Construct_UPackage__Script_SolarSystemVR();
			OuterClass = AMyCharacter::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_brainControlCommond = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("brainControlCommond"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(brainControlCommond, AMyCharacter), 0x0010000000020015);
				UProperty* NewProp_brainControlCommond_Inner = new(EC_InternalUseOnlyConstructor, NewProp_brainControlCommond, TEXT("brainControlCommond"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000020000);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("MyCharacter.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/MyCharacter.h"));
				MetaData->SetValue(NewProp_brainControlCommond, TEXT("Category"), TEXT("brainControl"));
				MetaData->SetValue(NewProp_brainControlCommond, TEXT("ModuleRelativePath"), TEXT("Public/MyCharacter.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyCharacter(Z_Construct_UClass_AMyCharacter, &AMyCharacter::StaticClass, TEXT("AMyCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyCharacter);
	UClass* Z_Construct_UClass_APawnMoveControl_NoRegister()
	{
		return APawnMoveControl::StaticClass();
	}
	UClass* Z_Construct_UClass_APawnMoveControl()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_SolarSystemVR();
			OuterClass = APawnMoveControl::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("PawnMoveControl.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/PawnMoveControl.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APawnMoveControl(Z_Construct_UClass_APawnMoveControl, &APawnMoveControl::StaticClass, TEXT("APawnMoveControl"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APawnMoveControl);
	UClass* Z_Construct_UClass_ASocketActor_NoRegister()
	{
		return ASocketActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ASocketActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_SolarSystemVR();
			OuterClass = ASocketActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SocketActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/SocketActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASocketActor(Z_Construct_UClass_ASocketActor, &ASocketActor::StaticClass, TEXT("ASocketActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASocketActor);
	UClass* Z_Construct_UClass_ATCPClient_NoRegister()
	{
		return ATCPClient::StaticClass();
	}
	UClass* Z_Construct_UClass_ATCPClient()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_SolarSystemVR();
			OuterClass = ATCPClient::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("TCPClient.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/TCPClient.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATCPClient(Z_Construct_UClass_ATCPClient, &ATCPClient::StaticClass, TEXT("ATCPClient"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATCPClient);
	UClass* Z_Construct_UClass_AMyPlayerController_NoRegister()
	{
		return AMyPlayerController::StaticClass();
	}
	UClass* Z_Construct_UClass_AMyPlayerController()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APlayerController();
			Z_Construct_UPackage__Script_SolarSystemVR();
			OuterClass = AMyPlayerController::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900284;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_brainControlCommond = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("brainControlCommond"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(brainControlCommond, AMyPlayerController), 0x0010000000020015);
				UProperty* NewProp_brainControlCommond_Inner = new(EC_InternalUseOnlyConstructor, NewProp_brainControlCommond, TEXT("brainControlCommond"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000020000);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("MyPlayerController.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/MyPlayerController.h"));
				MetaData->SetValue(NewProp_brainControlCommond, TEXT("Category"), TEXT("brainControl"));
				MetaData->SetValue(NewProp_brainControlCommond, TEXT("ModuleRelativePath"), TEXT("Public/MyPlayerController.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyPlayerController(Z_Construct_UClass_AMyPlayerController, &AMyPlayerController::StaticClass, TEXT("AMyPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyPlayerController);
	UClass* Z_Construct_UClass_ASolarSystemVRGameModeBase_NoRegister()
	{
		return ASolarSystemVRGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_ASolarSystemVRGameModeBase()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameModeBase();
			Z_Construct_UPackage__Script_SolarSystemVR();
			OuterClass = ASolarSystemVRGameModeBase::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900288;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SolarSystemVRGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("SolarSystemVRGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASolarSystemVRGameModeBase(Z_Construct_UClass_ASolarSystemVRGameModeBase, &ASolarSystemVRGameModeBase::StaticClass, TEXT("ASolarSystemVRGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASolarSystemVRGameModeBase);
	UClass* Z_Construct_UClass_ATCPConnection_NoRegister()
	{
		return ATCPConnection::StaticClass();
	}
	UClass* Z_Construct_UClass_ATCPConnection()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_SolarSystemVR();
			OuterClass = ATCPConnection::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("TCPConnection.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/TCPConnection.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATCPConnection(Z_Construct_UClass_ATCPConnection, &ATCPConnection::StaticClass, TEXT("ATCPConnection"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATCPConnection);
	UPackage* Z_Construct_UPackage__Script_SolarSystemVR()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/SolarSystemVR")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x0B2715AC;
			Guid.B = 0x86A87F48;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
