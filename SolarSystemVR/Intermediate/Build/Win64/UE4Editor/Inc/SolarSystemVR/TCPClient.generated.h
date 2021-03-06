// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SOLARSYSTEMVR_TCPClient_generated_h
#error "TCPClient.generated.h already included, missing '#pragma once' in TCPClient.h"
#endif
#define SOLARSYSTEMVR_TCPClient_generated_h

#define SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_RPC_WRAPPERS
#define SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesATCPClient(); \
	friend SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_ATCPClient(); \
	public: \
	DECLARE_CLASS(ATCPClient, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SolarSystemVR"), NO_API) \
	DECLARE_SERIALIZER(ATCPClient) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_INCLASS \
	private: \
	static void StaticRegisterNativesATCPClient(); \
	friend SOLARSYSTEMVR_API class UClass* Z_Construct_UClass_ATCPClient(); \
	public: \
	DECLARE_CLASS(ATCPClient, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SolarSystemVR"), NO_API) \
	DECLARE_SERIALIZER(ATCPClient) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATCPClient(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATCPClient) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATCPClient); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATCPClient); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATCPClient(ATCPClient&&); \
	NO_API ATCPClient(const ATCPClient&); \
public:


#define SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATCPClient(ATCPClient&&); \
	NO_API ATCPClient(const ATCPClient&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATCPClient); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATCPClient); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATCPClient)


#define SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_PRIVATE_PROPERTY_OFFSET
#define SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_9_PROLOG
#define SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_PRIVATE_PROPERTY_OFFSET \
	SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_RPC_WRAPPERS \
	SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_INCLASS \
	SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_PRIVATE_PROPERTY_OFFSET \
	SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_INCLASS_NO_PURE_DECLS \
	SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SolarSystemVR_Source_SolarSystemVR_Public_TCPClient_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
