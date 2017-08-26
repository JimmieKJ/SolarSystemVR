// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSystemVR.h"
#include "TCPClient.h"


// Sets default values
ATCPClient::ATCPClient() :mbCanSend(false), i_mTcpClient(0), i_mSocketActor(0)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATCPClient::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATCPClient::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATCPClient::Destroyed()
{
	if (clientSocket)
	{
		clientSocket->Destroyed();
		tClientSocket->Destroyed();
	}
	//Super::BeginDestroy();
}

void ATCPClient::ConnectToBrainControl()
{
	//ASocketActor* tClientSocket = new ASocketActor();
	if (!tClientSocket->SocketCreate("192.168.1.109", 2050))
	{
		return;
	}
	i_mTcpClient++;
	TCPConnectionListener(tClientSocket);
	//clientSocket->SocketSend("T");
}


void ATCPClient::TCPConnectionListener(ASocketActor* tClientSocket)
{
	//FPlatformProcess::Sleep(5);
	int32 dataSendLen = 0;
	while (1)
	{
		if (mbCanSend)
		{
			//ASocketActor* ConnectionSocket;
			bool isSend = tClientSocket->SocketSend("T");
			//bool isSend = ConnectionSocket->Send((uint8*)(TEXT("T")), 1, dataSendLen);
			GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Green, FString::Printf(TEXT("send T ...")));
			//UE_LOG(LogTemp, Warning, TEXT("send T ..."));
			if (!isSend)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("send T failed")));
				//UE_LOG(LogTemp, Warning, TEXT("send T failed"));
				continue;
			}
			//ASocketActor* receiveDataSocket = GetWorld()->SpawnActor<ASocketActor>();;
			//bool bClientCreate;
			if (clientSocket->mi_SocketNumber == 0)
				clientSocket->SocketCreate("192.168.1.109", 2051);

			clientSocket->SocketReceive();
			if (!mbCanSend)
			{
				i_mTcpClient--;
				Destroyed();
				break;
			}
		}
		Sleep(0);
	}
	//delete tClientSocket;
	//}
	/*}*/

	//if (ConnectionSocket != NULL)
	//{
	//	//Global cache of current Remote Address
	//	RemoteAddressForConnection = FIPv4Endpoint(RemoteAddress);

	//	//UE_LOG "Accepted Connection! WOOOHOOOO!!!";

	//	//can thread this too
	//	GetWorldTimerManager().ClearTimer(tcpSocketListenerTime_handler); // properly initialize
	//	GetWorldTimerManager().SetTimer(tcpSocketListenerTime_handler, this, &AATCPConnection::TCPSocketListener, 0.01, true); // SetTimer now needs an FTimerHandle
	//}

}
