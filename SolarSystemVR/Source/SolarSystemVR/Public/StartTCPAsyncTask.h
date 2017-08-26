// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "AsyncWork.h"
#include "TCPClient.h"
/**
 * 
 */
class SOLARSYSTEMVR_API StartTCPAsyncTask : public FNonAbandonableTask
{
public:
	StartTCPAsyncTask(ATCPClient* tcpConn);
	~StartTCPAsyncTask();

	/** Performs work on thread */
	void DoWork();
	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(StartTCPAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}
	//bool CanAbandon();
	//void Abandon();
public:
	ATCPClient* tcpConn;
	int flageInt;
};
