// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Networking.h"
#include "PawnMoveControl.h"
#include "SocketActor.generated.h"

UCLASS()
class SOLARSYSTEMVR_API ASocketActor : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ASocketActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	bool SocketCreate(FString IPStr, int32 port);
	bool SocketSend(FString meesage);
	void SocketReceive();
	FString StringFromBinaryArray(TArray<uint8> BinaryArray);
	void ActionSocket();
	void ActiveBrainClient();
	void Destroyed();
	void printMsgByBrainControl(TArray<TMap<FString, float>> tempArr);
	//void writeMsgToTxt(FString ReceivedUE4String);
public:
	int32 i_mMoveControlPrecision;
	APawnMoveControl* UAV;
	TArray<int32> frequencyIndex;
	FSocket *Host;
	FIPv4Address ip;
	FTimerHandle tcpSocketListenerTime_handler; // NEW
	int mi_SocketNumber;
};
