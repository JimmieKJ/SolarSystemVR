// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SocketActor.h"
#include "TCPClient.generated.h"

UCLASS()
class SOLARSYSTEMVR_API ATCPClient : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATCPClient();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//tcp链接的主函数入口
	void ConnectToBrainControl();
	//tcp此线程的主循环体
	void TCPConnectionListener(ASocketActor* clientSocket);

	void Destroyed();
public:
	int32 i_mTcpClient;
	int32 i_mSocketActor;
	bool mbCanSend;
	ASocketActor* clientSocket;
	ASocketActor* tClientSocket;
	
};
