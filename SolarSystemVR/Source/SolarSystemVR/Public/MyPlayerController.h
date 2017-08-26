// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "SocketActor.h"
#include "TCPClient.h"
#include "StartTCPAsyncTask.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SOLARSYSTEMVR_API AMyPlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()
public:
	virtual void PostInitializeComponents() override;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupInputComponent() override;
	
	void LaunchNetwork();
	virtual void BeginDestroy() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "brainControl")
	TArray<int32> brainControlCommond;
	FAutoDeleteAsyncTask<StartTCPAsyncTask>* taskTCP;
	ATCPClient* tcpConn;
	ASocketActor* clientSocket;
	
};
