// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PawnMoveControl.generated.h"

UCLASS()
class SOLARSYSTEMVR_API APawnMoveControl : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APawnMoveControl();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/**
	* 分开得到的脑控数据
	*/
	TArray<int32> getAnalysisDataFromLV(const FString brainControlDataLV);
	/**
	* 得到drone移动速度和方向
	*/
	TArray<int32> pushToBCDataMap(TMap<FString, float> temp);


	TMap<FString, float> getFloatArr(const TArray<FString> InArray);
	void writeMsgToTxt(FString ReceivedUE4String);
public:
	TArray<TMap<FString, float>> brainControlDataArray;
	int32 i_mMoveControlPrecision;
protected:
	TArray<int32> droneMoveFormardSpeed{ 300,150,80,0 };
	TArray<int32> droneMoveRightSpeed{ 20,10,5,0 };
	
};
