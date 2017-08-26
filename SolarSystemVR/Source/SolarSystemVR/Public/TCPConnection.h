// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SocketActor.h"
#include "Networking.h"
#include "AsyncWork.h"
#include "TCPConnection.generated.h"

UCLASS()
class SOLARSYSTEMVR_API ATCPConnection : public AActor
{
	GENERATED_BODY()
	
public:

	FSocket* lpListenerSocket;
	FSocket* lpConnectionSocket;
	bool bCanSend = false;
	bool bClientCreate = false;
	bool bConnection = true;
	FIPv4Endpoint RemoteAddressForConnection;
	FTimerHandle tcpSocketListenerTime_handler; // NEW
	FTimerHandle tcpConnectionListenerTime_handler; // NEW
	ASocketActor* lpClientSocket;
	TStatId threadId;
public:	
	// Sets default values for this actor's properties
	ATCPConnection();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//开始监听本地回环地址的一个端口
	void LaunchNetWork();

	//开始监听端口
	bool StartTCPRecevier(const FString& socketName,const FString& ip, const int32 port);
	
	bool FormatIPV4ToNumber(const FString& ip, uint8(&out)[4]);

	FString StringFromBinaryArray(TArray<uint8> BinaryArray);
	void LaunchNetwork();

	virtual void BeginDestroy(); // without this, the code runs well -- once. The second time, the Editor crashes.

	FSocket* CreateTCPConnectionListener(const FString& YourChosenSocketName, const FString& TheIP, const int32 ThePort, const int32 ReceiveBufferSize = 2 * 1024 * 1024);
	void TCPConnectionListener();
	void TCPSocketListener();
};
