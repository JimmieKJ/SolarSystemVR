// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSystemVR.h"
#include "SocketActor.h"


// Sets default values
ASocketActor::ASocketActor() :mi_SocketNumber(0), i_mMoveControlPrecision(1)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASocketActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASocketActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASocketActor::ActiveBrainClient()
{
	GetWorldTimerManager().ClearTimer(tcpSocketListenerTime_handler); // properly initialize
	GetWorldTimerManager().SetTimer(tcpSocketListenerTime_handler, this, &ASocketActor::ActionSocket, 0.02, true); // SetTimer now needs an FTimerHandle
}

void ASocketActor::ActionSocket()
{
	/*while (1) {*/
	if (SocketCreate("192.168.1.109", 2051))
	{
		SocketReceive();
		//GetWorldTimerManager().ClearTimer(tcpSocketListenerTime_handler); // properly initialize
		//GetWorldTimerManager().SetTimer(tcpSocketListenerTime_handler, this, &ASocketActor::SocketReceive, 0.2, true);
		/*while (1)
		{
		SocketReceive();
		}
		return;
		}*/
		//}
	}
}

bool ASocketActor::SocketCreate(FString IPStr, int32 port)
{

	FIPv4Address::Parse(IPStr, ip);

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(port);

	Host = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

	if (Host->Connect(*addr))
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("Connect Succ!"));
		//UE_LOG(LogTemp, Warning, TEXT("Connect Succ!"));
		++mi_SocketNumber;
		return true;
		/*
		FString seriallized = TEXT("LoadPlayer|1");
		TCHAR *seriallizedChar = seriallized.GetCharArray().GetData();
		int32 size = FCString::Strlen(seriallizedChar);
		int32 sent = 0;

		if (Host->Send((uint8*)TCHAR_TO_UTF8(seriallizedChar),size,sent))
		{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("_____Send Succ!"));
		UE_LOG(LogTemp, Warning, TEXT("_____Send Succ!"));
		}
		else
		{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("_____Send Succ!"));
		UE_LOG(LogTemp, Warning, TEXT("_____Send Succ!"));
		}
		*/

	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("Connect failed!"));
		//UE_LOG(LogTemp, Warning, TEXT("Connect failed!"));
		return false;
	}

}

//void ASocketActor::writeMsgToTxt(FString ReceivedUE4String)
//{
//	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();
//	FString gameRootDir = FPaths::ConvertRelativePathToFull(FPaths::RootDir());
//	FString m_statisticsDir = gameRootDir + "Statistic/";
//	//FString macAddr = FGenericPlatformMisc::GetMacAddressString();
//	FString absolutePath = m_statisticsDir + TEXT("test.txt");
//	if (!file.DirectoryExists(*m_statisticsDir))
//	{
//		file.CreateDirectory(*m_statisticsDir);
//	}
//	//创建文件
//	IFileHandle* m_filehandle;
//	m_filehandle = file.OpenWrite(*absolutePath, true);
//
//	//获取时间
//	FString timestamp = FDateTime::Now().ToString();
//	const static TCHAR* endline = TEXT("\r\n");
//	const static TCHAR* space = TEXT(" ");
//
//	//写文件
//	//字符串编码格式转换
//
//	m_filehandle->Write((const uint8*)TCHAR_TO_ANSI(*ReceivedUE4String), FCStringAnsi::Strlen(TCHAR_TO_ANSI(*ReceivedUE4String)));
//
//	delete m_filehandle;
//}

bool ASocketActor::SocketSend(FString meesage)
{
	//FString seriallized = TEXT("LoadPlayer|1");
	TCHAR *seriallizedChar = meesage.GetCharArray().GetData();
	int32 size = FCString::Strlen(seriallizedChar) + 1;
	int32 sent = 0;
	bool sendSuccess = false;
	if (Host->Send((uint8*)TCHAR_TO_UTF8(seriallizedChar), size, sent))
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("_____Send Succ!"));
		//UE_LOG(LogTemp, Warning, TEXT("_____Send Succ!"));
		sendSuccess = true;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("_____Send failed!"));
		//UE_LOG(LogTemp, Warning, TEXT("_____Send failed!"));
	}
	return sendSuccess;
}

void ASocketActor::SocketReceive()
{
	if (!Host)
	{
		return;
	}

	TArray<uint8> ReceiveData;
	uint32 size;
	uint8 element = 0;
	FPlatformProcess::Sleep(0.2);
	while (Host->HasPendingData(size))
	{
		ReceiveData.Init(element, FMath::Min(size, 65507u));

		int32 read = 0;
		Host->Recv(ReceiveData.GetData(), ReceiveData.Num(), read);
	}

	if (ReceiveData.Num() <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString("cant receive data."));
		return;
	}
	FString log = "Total Data read! num: " + FString::FromInt(ReceiveData.Num() <= 0);

	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, log);
	//UE_LOG(LogTemp, Warning, TEXT("Recv log:   %s"), *log);

	const FString ReceivedUE4String = StringFromBinaryArray(ReceiveData);
	//UAV = MakeShareable(new UAV());
	//writeMsgToTxt(ReceivedUE4String);
	//无人机算法类UAVMoveControl创建
	if (UAV == nullptr)
		UAV = NewObject<APawnMoveControl>();
	UAV->i_mMoveControlPrecision = i_mMoveControlPrecision;
	frequencyIndex = UAV->getAnalysisDataFromLV(ReceivedUE4String);
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, FString::FromInt(frequencyIndex));
	log = "Server:" + ReceivedUE4String;
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, log);
	//UE_LOG(LogTemp, Warning, TEXT("*** %s"), *log);
	//UE_LOG(LogTemp, Warning, TEXT("--------------------------------------------"));
	printMsgByBrainControl(UAV->brainControlDataArray);
	//BeginDestroy();
}

void ASocketActor::printMsgByBrainControl(TArray<TMap<FString, float>> brainControlDataArray)
{
	FString brainDataStr;
	if (brainControlDataArray.Num() == 5)
	{
		for (int32 i = 0; i < brainControlDataArray.Num(); i++)
		{
			for (TPair<FString, float>& element : brainControlDataArray[i])
			{
				//UE_LOG(LogTemp, Warning, TEXT("*** %s"), *(element.Key));
			}
		}

	}
}

FString ASocketActor::StringFromBinaryArray(TArray<uint8> BinaryArray)
{
	return FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(BinaryArray.GetData())));
}

void ASocketActor::Destroyed()
{

	//Super::BeginDestroy();
	//UE_LOG(LogTemp, Warning, TEXT("Closing Sockets"));
	if (Host != nullptr) {
		Host->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Host);
	}
}

