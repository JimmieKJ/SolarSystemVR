// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSystemVR.h"
#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void AMyPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	/*if (GEngine)
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, TEXT("I'm using AMyPlayerController!"));
	*/

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, TEXT("I'm using AMyPlayerController!"));

	if (tcpConn == nullptr)
	{
		tcpConn = GetWorld()->SpawnActor<ATCPClient>();

		tcpConn->clientSocket = GetWorld()->SpawnActor<ASocketActor>();
		tcpConn->tClientSocket = GetWorld()->SpawnActor<ASocketActor>();
		//if(tcpConn)
		//	tcpConn->LaunchNetwork();

		taskTCP = new FAutoDeleteAsyncTask<StartTCPAsyncTask>(tcpConn);

		if (taskTCP)
			taskTCP->StartBackgroundTask();
		
	}

	
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (tcpConn != nullptr && tcpConn->tClientSocket != nullptr)
		brainControlCommond = tcpConn->tClientSocket->frequencyIndex;
	//GetCharacter()
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("TCPServer", IE_Pressed, this, &AMyPlayerController::LaunchNetwork);
}



void AMyPlayerController::LaunchNetwork()
{
	tcpConn->mbCanSend = true;
}

void AMyPlayerController::BeginDestroy()
{
	Super::BeginDestroy();
	if (tcpConn)
	{
		//tcpConn->canConnection = false;
		tcpConn->mbCanSend = false;
		taskTCP->Task.flageInt = 0;
		while (tcpConn->i_mTcpClient)
		{
			Sleep(0);
		}
	}
}