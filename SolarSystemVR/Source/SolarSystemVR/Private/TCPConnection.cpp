// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSystemVR.h"
#include "TCPConnection.h"


// Sets default values
ATCPConnection::ATCPConnection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATCPConnection::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATCPConnection::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATCPConnection::LaunchNetWork()
{
	if (!StartTCPRecevier("BrainControlSocket", "127.0.0.1", 2050))
	{
		return;
	}
}

bool ATCPConnection::StartTCPRecevier(const FString & socketName, const FString& ip, const int32 port)
{
	lpListenerSocket = CreateTCPConnectionListener(socketName, ip, port);
	if(!lpListenerSocket)
	{
		return false;
	}
	TCPConnectionListener();
	return true;
}

bool ATCPConnection::FormatIPV4ToNumber(const FString & TheIP, uint8(&Out)[4])
{
	TheIP.Replace(TEXT(" "), TEXT(""));

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//						   IP 4 Parts

	//String Parts
	TArray<FString> Parts;
	TheIP.ParseIntoArray(Parts, TEXT("."), true);
	if (Parts.Num() != 4)
		return false;

	//String to Number Parts
	for (int32 i = 0; i < 4; ++i)
	{
		Out[i] = FCString::Atoi(*Parts[i]);
	}

	return true;
}

FString ATCPConnection::StringFromBinaryArray(TArray<uint8> BinaryArray)
{
	return FString();
}

void ATCPConnection::LaunchNetwork()
{
}

void ATCPConnection::BeginDestroy()
{
	// Call the base class
	Super::BeginDestroy();
	UE_LOG(LogTemp, Warning, TEXT("Closing Sockets"));
	if (lpListenerSocket != nullptr) {
		lpListenerSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(lpListenerSocket);
	}

	if (lpConnectionSocket != nullptr) {
		lpConnectionSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(lpConnectionSocket);
	}

}

FSocket * ATCPConnection::CreateTCPConnectionListener(const FString & YourChosenSocketName, const FString & TheIP, const int32 ThePort, const int32 ReceiveBufferSize)
{
	uint8 IP4Nums[4];
	if(!FormatIPV4ToNumber(TheIP,IP4Nums))
		return nullptr;
	FIPv4Endpoint Endpoint(FIPv4Address(IP4Nums[0], IP4Nums[1], IP4Nums[2], IP4Nums[3]), ThePort);
	FSocket* ListenSocket = FTcpSocketBuilder(*YourChosenSocketName)
		.AsBlocking()
		.AsReusable()
		.BoundToEndpoint(Endpoint)
		.Listening(8);
	//Set Buffer Size
	int32 NewSize = 0;
	ListenSocket->SetReceiveBufferSize(ReceiveBufferSize, NewSize);
	ListenSocket->SetSendBufferSize(ReceiveBufferSize, NewSize);
	//Done!
	return ListenSocket;
}

void ATCPConnection::TCPConnectionListener()
{
	TSharedRef<FInternetAddr> RemoteAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	checkCode(
		if (lpConnectionSocket)
		{
			lpConnectionSocket->Close();
			ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(lpConnectionSocket);
		})
	lpConnectionSocket = lpListenerSocket->Accept(*RemoteAddress, TEXT("T"));
	int32 dataSendLen = 0;
	while (true)
	{
		if (!bConnection)
			return;
		if (bCanSend)
		{
			checkCode(
				if (lpConnectionSocket)
				{
					bool isSend = lpConnectionSocket->Send((uint8*)(TEXT("T")), 1, dataSendLen);
					GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Green, FString::Printf(TEXT("send T ...")));
					UE_LOG(LogTemp, Warning, TEXT("send T ..."));
					if (!isSend)
					{
						GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("send T failed")));
						UE_LOG(LogTemp, Warning, TEXT("send T failed"));
						continue;
					}
					bClientCreate = lpClientSocket->SocketCreate("127.0.0.1", 2051);
					if (bClientCreate)
					{
						lpClientSocket->SocketReceive();
					}

				}
			)
		}
	}
}

void ATCPConnection::TCPSocketListener()
{
}

