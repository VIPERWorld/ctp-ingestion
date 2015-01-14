#include "stdafx.h"

#include <fstream>

#include "StockMarketApi.h"
#include "StockMetaInfo.h"
#include "..\database\DBManager.h"

using namespace std;

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace CTP_Ingestion;

StockMarketApi::StockMarketApi()
{
}

StockMarketApi::~StockMarketApi()
{
}

void StockMarketApi::SubscribeAllStockMarketData(String^ sql_ip, String^ sql_port, String^ sql_userID, String^ sql_passwd)
{
	DBManager^ db = gcnew DBManager(sql_ip, sql_port, sql_userID, sql_passwd);

	ArrayList^ list = db->getStockWatchList();

	for (int i = 0; i < list->Count; i++)
	{
		StockMetaInfo^ stockMetaInfo = (StockMetaInfo^) list[i];

		char* code = (char*)(void*)Marshal::StringToHGlobalAnsi(stockMetaInfo->getCode());
		char* exchange = (char*)(void*)Marshal::StringToHGlobalAnsi(stockMetaInfo->getExchange());

		char* Instruments[1];
		memset(Instruments,0,sizeof(Instruments));
		Instruments[0] = code;

		int a = SubscribeMarketData(Instruments, 1,exchange);
		printf("%d\n", a);

		Marshal::FreeHGlobal((System::IntPtr)(void*)code);
		Marshal::FreeHGlobal((System::IntPtr)(void*)exchange);
	}
}

//��������
//char * Instruments[10];
//memset(Instruments,0,sizeof(Instruments));
//Instruments[0] = "150019";
//Instruments[0] = "000001";
//Instruments[0] = "AG1406";

//SZE	���ڹ�Ʊ������
//SSE   �Ϻ�֤ȯ������
//CFFEX �й����ڽ����� �н��� J
//CZCE  ֣����Ʒ������ ֣���� Z
//DCE   ������Ʒ������ ������ D
//SHFE  �Ϻ��ڻ������� ������ S
//m_pMdApi->SubscribeMarketData (Instruments,10,"SSE");
//m_pMdApi->SubscribeMarketData(Instruments,1,"SZE");
