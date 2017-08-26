// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSystemVR.h"
#include "PawnMoveControl.h"


// Sets default values
APawnMoveControl::APawnMoveControl():i_mMoveControlPrecision(1)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APawnMoveControl::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnMoveControl::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

TArray<int32> APawnMoveControl::getAnalysisDataFromLV(const FString brainControlDataLV)
{
	TMap<FString, float> temp;
	TArray<FString> OutArray;

	brainControlDataLV.ParseIntoArrayLines(OutArray);
	temp = getFloatArr(OutArray);
	TArray<int32> frequencyIndex = pushToBCDataMap(temp);
	//brainControlDataLV.ParseIntoArray(OutArray, &spliteChar);
	return frequencyIndex;
}

TArray<int32> APawnMoveControl::pushToBCDataMap(TMap<FString, float> temp)
{
	TArray<FString> tempKeys;
	temp.GetKeys(tempKeys);
	bool bUse = true;
	for (int iKey = 0; iKey < tempKeys.Num(); ++iKey)
	{
		if (tempKeys[iKey].Contains(FString("-0")))
		{
			bUse = false;
			break;
		}
	}
	if (bUse)
	{
		if (brainControlDataArray.Num() >= 4)
		{
			brainControlDataArray.RemoveAt(0);
		}
		brainControlDataArray.Add(temp);
	}
	int32 indexControl = -1;
	int32 ControlMoveSpeed = 0;
	TArray<int32> BCDataArr;
	if (brainControlDataArray.Num() == 4)
	{
		int32 firstFrequencyCount = 0;
		int32 secondFrequencyCount = 0;
		int32 thirdFrequencyCount = 0;

		int32 firstQualityCount = 0;
		int32 secondQualityCount = 0;
		int32 thirdQualityCount = 0;
		TArray<FString> qualityArr;
		TArray<FString> keyPicArr;

		int32 BCDataArrLen = brainControlDataArray.Num();
		for (int32 i = 0; i < BCDataArrLen; i++)
		{
			for (TPair<FString, float>& element : brainControlDataArray[i])
			{
				qualityArr.Insert(FString::SanitizeFloat(element.Value), 0);
				//qualityArr.Add(element.Value);
				FString tempLeft = "";
				FString tempRight = "";
				element.Key.Split(" ", &tempLeft, &tempRight);
				keyPicArr.Insert(tempLeft, 0);
				if (FCString::Atoi(*tempLeft) == 1)
				{
					++firstFrequencyCount;
					firstQualityCount = firstQualityCount + element.Value;
				}
				else if (FCString::Atoi(*tempLeft) == 2)
				{
					++secondFrequencyCount;
					secondQualityCount = secondQualityCount + element.Value;
				}
				else if (FCString::Atoi(*tempLeft) == 3)
				{
					++thirdFrequencyCount;
					thirdQualityCount = thirdQualityCount + element.Value;
				}
			}
		}
		if (keyPicArr[0].Equals(keyPicArr[1]) && qualityArr[0].Equals(qualityArr[1]) && qualityArr[0].Contains(FString("5")))
		{
			indexControl = FCString::Atoi(*keyPicArr[0]);
			ControlMoveSpeed = indexControl == 1 ? droneMoveFormardSpeed[0] : (indexControl == 2 ? droneMoveRightSpeed[0] : 0 - droneMoveRightSpeed[0]);
		}
		if (indexControl == -1)
		{
			int32 allFrequencyCount = 4;
			int32 FrequencyIn = (firstQualityCount > secondQualityCount ? (firstQualityCount > thirdQualityCount ? 1 : 3) : (secondQualityCount > thirdQualityCount ? 2 : 3));

			switch (FrequencyIn)
			{
			case 1:
			{
				if ((firstFrequencyCount / allFrequencyCount > 0.7*i_mMoveControlPrecision) && firstQualityCount >= 12 * i_mMoveControlPrecision)
				{
					indexControl = FrequencyIn;
					ControlMoveSpeed = droneMoveFormardSpeed[1];
				}
				else if ((firstFrequencyCount / allFrequencyCount >= 0.5*i_mMoveControlPrecision) && firstQualityCount >= 8 * i_mMoveControlPrecision)
				{
					indexControl = FrequencyIn;
					ControlMoveSpeed = droneMoveFormardSpeed[2];
				}
				else
				{
					indexControl = -1;
					ControlMoveSpeed = 0;
				}
				break;
			}
			case 2:
			{
				if ((secondFrequencyCount / allFrequencyCount > 0.7*i_mMoveControlPrecision) && secondQualityCount >= 12 * i_mMoveControlPrecision)
				{
					indexControl = FrequencyIn;
					ControlMoveSpeed = droneMoveRightSpeed[1];
				}
				else if ((secondFrequencyCount / allFrequencyCount >= 0.5*i_mMoveControlPrecision) && secondQualityCount >= 8 * i_mMoveControlPrecision)
				{
					indexControl = FrequencyIn;
					ControlMoveSpeed = droneMoveRightSpeed[2];
				}
				else
				{
					indexControl = -1;
					ControlMoveSpeed = 0;
				}
				break;
			}
			case 3:
			{
				if ((thirdFrequencyCount / allFrequencyCount > 0.7*i_mMoveControlPrecision) && thirdQualityCount >= 12 * i_mMoveControlPrecision)
				{
					indexControl = FrequencyIn;
					ControlMoveSpeed = 0 - droneMoveRightSpeed[1];
				}
				else if ((thirdFrequencyCount / allFrequencyCount >= 0.5*i_mMoveControlPrecision) && thirdQualityCount >= 8 * i_mMoveControlPrecision)
				{
					indexControl = FrequencyIn;
					ControlMoveSpeed = 0 - droneMoveRightSpeed[2];
				}
				else
				{
					indexControl = -1;
					ControlMoveSpeed = 0;
				}
				break;
			}
			default:
			{
				break;
			}
			}

		}
		/*for(int32 i = 0,int BCDataArrLen = brainControlDataArray.Num(); i < BCDataArrLen; i++)
		{
		for (TPair<FString, float>& element : brainControlDataArray[i])
		{
		if (element.Value >= 9)
		++canGetPicNum;
		if (element.Value >= 2.5f)
		{
		FString tempLeft = "";
		FString tempRight = "";
		element.Key.Split(" ", &tempLeft, &tempRight);
		if (tempLeft == "0")
		++firstFrequencyCount;
		else if (tempLeft == "1")
		++secondFrequencyCount;
		else if (tempLeft == "2")
		++thirdFrequencyCount;
		}
		++count;
		}
		}
		int32 maxCountFrequency = (firstFrequencyCount > secondFrequencyCount ? (firstFrequencyCount > thirdFrequencyCount ? firstFrequencyCount : thirdFrequencyCount) : (secondFrequencyCount > thirdFrequencyCount ? secondFrequencyCount : thirdFrequencyCount));
		int32 FrequencyIn = (firstFrequencyCount > secondFrequencyCount ? (firstFrequencyCount > thirdFrequencyCount ? 1 : 3) : (secondFrequencyCount > thirdFrequencyCount ? 2 : 3));
		float percentMaxFrequency = (float)maxCountFrequency / (float)count;
		if (percentMaxFrequency >= 0.8)
		{
		if(canGetPicNum > 0)
		indexControl = FrequencyIn;
		}
		//writeMsgToTxt(FString::FromInt(indexControl));
		*/
	}
	BCDataArr.Add(indexControl);
	BCDataArr.Add(ControlMoveSpeed);
	//writeMsgToTxt(FString::FromInt(indexControl));
	//writeMsgToTxt(FString::FromInt(ControlMoveSpeed));
	return BCDataArr;
}

TMap<FString, float> APawnMoveControl::getFloatArr(const TArray<FString> InArray)
{
	TArray<FString> OutArray;
	FString spliteChar(" ");
	FString tempLeft = "";
	FString tempRight = "";
	TMap<FString, float> BCDataMap;
	for (int32 i = 0; i < InArray.Num(); i++) {
		InArray[i].Split(": ", &tempLeft, &tempRight);
		if (tempLeft.Contains("symbol-1s"))
		{
			//writeMsgToTxt(tempRight);
			const TCHAR* str = *spliteChar;
			tempRight.ParseIntoArray(OutArray, str);
			float temp = FCString::Atof(*OutArray[1]);
			FString FSIndex = OutArray[0];
			if (FSIndex.Contains("0"))
				FSIndex = "-0";
			//for (int32 j = 0; j < OutArray.Num(); j++) {//ourArray[1,5]
			//	FString tempStr(OutArray[j]);
			//	const TCHAR* fStr = *tempStr;
			//	float distanceFloat = FCString::Atof(fStr);
			//	if (distanceFloat > temp)
			//	{
			//		temp = distanceFloat;
			//		tIndex = j;
			//	}
			//}
			FString mapKey = FSIndex + " " + tempLeft;
			BCDataMap.Add(mapKey, temp);
			break;
		}
	}
	return BCDataMap;
}

void APawnMoveControl::writeMsgToTxt(FString ReceivedUE4String)
{
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();
	FString gameRootDir = FPaths::ConvertRelativePathToFull(FPaths::RootDir());
	FString m_statisticsDir = gameRootDir + "Statistic/";
	//FString macAddr = FGenericPlatformMisc::GetMacAddressString();
	FString absolutePath = m_statisticsDir + TEXT("test.txt");
	if (!file.DirectoryExists(*m_statisticsDir))
	{
		file.CreateDirectory(*m_statisticsDir);
	}
	//创建文件
	IFileHandle* m_filehandle;
	m_filehandle = file.OpenWrite(*absolutePath, true);

	//获取时间
	FString timestamp = FDateTime::Now().ToString();
	const static TCHAR* endline = TEXT("\r\n");

	//写文件
	//字符串编码格式转换

	m_filehandle->Write((const uint8*)TCHAR_TO_ANSI(*ReceivedUE4String), FCStringAnsi::Strlen(TCHAR_TO_ANSI(*ReceivedUE4String)));
	m_filehandle->Write((const uint8*)TCHAR_TO_ANSI(endline), FCStringAnsi::Strlen(TCHAR_TO_ANSI(endline)));
	delete m_filehandle;
}

