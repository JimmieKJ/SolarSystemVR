// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSystemVR.h"
#include "StartTCPAsyncTask.h"

StartTCPAsyncTask::StartTCPAsyncTask(ATCPClient* tcpConnP) :flageInt(-1)
{
	tcpConn = tcpConnP;
}



StartTCPAsyncTask::~StartTCPAsyncTask()
{
}
//bool StartTCPAsyncTask::CanAbandon()
//{
//	return false;
//}
//
//void StartTCPAsyncTask::Abandon()
//{
//	checkCode(
//		if (tcpConn) {
//			tcpConn->canSend = false;
//			tcpConn->canConnection = false;
//			tcpConn->clientSocket->BeginDestroy();
//			tcpConn->BeginDestroy();
//		}
//	)
//}

void StartTCPAsyncTask::DoWork()
{
	flageInt = flageInt + 2;
	if (flageInt == 1)
	{
		tcpConn->ConnectToBrainControl();
		//tcpConn->threadId = GetStatId();
	}
	if (flageInt == 2)
	{
		tcpConn->BeginDestroy();
	}
}
