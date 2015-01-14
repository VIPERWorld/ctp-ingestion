#pragma once

#include "ThostFtdcUserApiStructSSE.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_MD_API_EXPORT
#define MD_API_EXPORT __declspec(dllexport)
#else
#define MD_API_EXPORT __declspec(dllimport)
#endif
#else
#define MD_API_EXPORT 
#endif

class CZQThostFtdcMdSpi
{
public:
	///6.4.1 ���ͻ����뽻���й�ϵͳ������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected() {};
	
	///6.4.2 ���ͻ����뽻���й�ϵͳͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ��������Զ�������ַ��������ԭ��ע��ĵ�ַ��Ҳ������ϵͳ֧�ֵ��������õ�ͨ�ŵ�ַ�����ɳ����Զ�ѡ��
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason) {};
	
	///6.4.3 ������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse) {};
	
	///6.4.4 ���ͻ��˷�����¼����֮�󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���ã�֪ͨ�ͻ��˵�¼�Ƿ�ɹ���
	virtual void OnRspUserLogin(CZQThostFtdcRspUserLoginField *pRspUserLogin, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.5 ���ͻ��˷����˳�����֮�󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���ã�֪ͨ�ͻ����˳��Ƿ�ɹ���
	virtual void OnRspUserLogout(CZQThostFtdcUserLogoutField *pUserLogout, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.6 �û������޸�Ӧ�𡣵��ͻ��˷����û������޸�ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	//virtual void OnRspUserPasswordUpdate(CZQThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.7 �ʽ��˻��������Ӧ�𡣵��ͻ��˷����ʽ��˻��������ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	//virtual void OnRspTradingAccountPasswordUpdate(CZQThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.8 ����û�����ĳ���֪ͨ��
	virtual void OnRspError(CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/*///6.4.9 ����¼��Ӧ�𡣵��ͻ��˷���������¼��ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspOrderInsert(CZQThostFtdcInputOrderField *pInputOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.10 ��������Ӧ�𡣱����������������ĳ����������Ĺ��𡢱����ļ���������޸ġ����ͻ��˷�������������ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspOrderAction(CZQThostFtdcOrderActionField *pOrderAction,CZQThostFtdcRspInfoField *pRspInfo,int nRequestID,bool bIsLast) {};

	///6.4.11 ��ѯ��󱨵�����Ӧ�𡣵��ͻ��˷�����ѯ��󱨵�����ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQueryMaxOrderVolume(CZQThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.12 Ͷ���߽�����ȷ��Ӧ�𡣵��ͻ��˷���Ͷ���߽�����ȷ��ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspSettlementInfoConfirm(CZQThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.13 ���������ʽ�ת�ڻ���Ӧ�����ͻ��˷������������ʽ�ת�ڻ�ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspTransferBankToFuture(CZQThostFtdcTransferBankToFutureRspField *pTransferBankToFutureRsp, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.14 �����ڻ��ʽ�ת������Ӧ�����ͻ��˷��������ڻ��ʽ�ת����ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspTransferFutureToBank(CZQThostFtdcTransferFutureToBankRspField *pTransferFutureToBankRsp, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.15 �����ѯ�����ʽ���Ӧ�����ͻ��˷��������ѯ�����ʽ�ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspTransferQryBank(CZQThostFtdcTransferQryBankRspField *pTransferQryBankRsp, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.16 �����ѯ���н�����ϸ��Ӧ�����ͻ��˷��������ѯ���н�����ϸָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspTransferQryDetail(CZQThostFtdcTransferQryDetailRspField *pTransferQryDetailRsp, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.17 ������ѯ���󡣵��ͻ��˷���������ѯָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQryOrder(CZQThostFtdcOrderField *pOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.18 �ɽ�����ѯӦ�𡣵��ͻ��˷����ɽ�����ѯָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQryTrade(CZQThostFtdcTradeField *pTrade, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.19 ��Ա�ͻ���ѯӦ�𡣵��ͻ��˷�����Ա�ͻ���ѯָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQryInvestor(CZQThostFtdcInvestorField *pInvestor, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.20 Ͷ���ֲֲ߳�ѯӦ�𡣵��ͻ��˷���Ͷ���ֲֲ߳�ѯָ��󣬺����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQryInvestorPosition(CZQThostFtdcInvestorPositionField *pInvestorPosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.21 �����ѯ�ʽ��˻���Ӧ�����ͻ��˷��������ѯ�ʽ��˻�ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQryTradingAccount(CZQThostFtdcTradingAccountField *pTradingAccount, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.22 �����ѯ���ױ�����Ӧ�����ͻ��˷��������ѯ���ױ���ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQryTradingCode(CZQThostFtdcTradingCodeField *pTradingCode, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.23 �����ѯ��������Ӧ�����ͻ��˷��������ѯ������ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQryExchange(CZQThostFtdcExchangeField *pExchange, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.24 �����ѯ��Լ��Ӧ�����ͻ��˷��������ѯ��Լָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQryInstrument(CZQThostFtdcInstrumentField *pInstrument, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};*/

	///6.4.25 �����ѯ������Ӧ�����ͻ��˷��������ѯ����ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	//virtual void OnRspQryDepthMarketData(CZQThostFtdcDepthMarketDataField *pDepthMarketData, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/*///6.4.26 �����ѯͶ���߽�������Ӧ�����ͻ��˷��������ѯͶ���߽�����ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQrySettlementInfo(CZQThostFtdcSettlementInfoField *pSettlementInfo, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.27 �����ѯת��������Ӧ�����ͻ��˷��������ѯת������ָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQryTransferBank(CZQThostFtdcTransferBankField *pTransferBank, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.28 �����ѯͶ���ֲ߳���ϸ��Ӧ�����ͻ��˷������������ѯͶ���ֲ߳���ϸָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQryInvestorPositionDetail(CZQThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.29 �����ѯ�ͻ�֪ͨ��Ӧ�����ͻ��˷��������ѯ�ͻ�ָ֪ͨ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á�
	virtual void OnRspQryNotice(CZQThostFtdcNoticeField *pNotice, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.30 ��Լ��ѯӦ�𡣵��ͻ��˷�����Լ��ѯָ��󣬽����й�ϵͳ������Ӧʱ���÷����ᱻ���á� --- Duplicate of 6.4.24
	//virtual void OnRspQryInstrument(CZQThostFtdcInstrumentField *pInstrument, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.31 �ɽ��ر����������ɽ�ʱ�����й�ϵͳ��֪ͨ�ͻ��ˣ��÷����ᱻ���á� --- Can not found
	//virtual void OnRtnTrade(CZQThostFtdcTradeField *pTrade);

	///6.4.32 �����ر������ͻ��˽��б���¼�롢��������������ԭ���粿�ֳɽ������±���״̬�����仯ʱ�������й�ϵͳ������֪ͨ�ͻ��ˣ��÷����ᱻ���á� --- Can not found
	//virtual void OnRtnOrder(CZQThostFtdcOrderField *pOrder);

	///6.4.33 ����¼�����ر����ɽ����й�ϵͳ����֪ͨ�ͻ��ˣ��÷����ᱻ���á�
	virtual void OnErrRtnOrderInsert(CZQThostFtdcInputOrderField *pInputOrder, CZQThostFtdcRspInfoField *pRspInfo) {};

	///6.4.34 ���۲�������ر����ɽ����й�ϵͳ����֪ͨ�ͻ��ˣ��÷����ᱻ���á�
	virtual void OnErrRtnOrderAction (CZQThostFtdcOrderActionField *pOrderAction, CZQThostFtdcRspInfoField *pRspInfo) {};

	///6.4.35 ��ѯ����ȷ����Ӧ���ɽ����й�ϵͳ����֪ͨ�ͻ��ˣ��÷����ᱻ���á�
	virtual void OnRspQrySettlementInfoConfirm(CZQThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.36 �����ѯǩԼ������Ӧ��
	virtual void OnRspQryContractBank(CZQThostFtdcContractBankField *pContractBank, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.37 �����ѯԤ����Ӧ��
	virtual void OnRspQryParkedOrder(CZQThostFtdcParkedOrderField *pParkedOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.38 �����ѯԤ�񳷵���Ӧ��
	virtual void OnRspQryParkedOrderAction(CZQThostFtdcParkedOrderActionField *pParkedOrderAction, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.39 �����ѯͶ���ֲ߳���ϸ��Ӧ��
	virtual void OnRspQryInvestorPositionCombineDetail(CZQThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.40 Ԥ��¼��������Ӧ��
	virtual void OnRspParkedOrderInsert(CZQThostFtdcParkedOrderField *pParkedOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.41 Ԥ�񳷵�¼��������Ӧ��
	virtual void OnRspParkedOrderAction(CZQThostFtdcParkedOrderActionField *pParkedOrderAction, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.42 ɾ��Ԥ����Ӧ��
	virtual void OnRspRemoveParkedOrder(CZQThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///6.4.43 ɾ��Ԥ�񳷵���Ӧ��
	virtual void OnRspRemoveParkedOrderAction(CZQThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};*/

	///��������Ӧ��
	virtual void OnRspSubMarketData(CZQThostFtdcSpecificInstrumentField *pSpecificInstrument, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ȡ����������Ӧ��
	virtual void OnRspUnSubMarketData(CZQThostFtdcSpecificInstrumentField *pSpecificInstrument, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CZQThostFtdcDepthMarketDataField *pDepthMarketData) {};
};

class MD_API_EXPORT CZQThostFtdcMdApi
{
public:
	///6.5.1 ����һ��CZQThostFtdcTradeApi��һ��ʵ��������ͨ��new��������
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@return ��������UserApi
	///modify for udp marketdata
	static CZQThostFtdcMdApi *CreateFtdcMdApi(const char *pszFlowPath = "", const bool bIsUsingUdp=false);
	
	///6.5.2 �ͷ�һ��CZQThostFtdcTradeApiʵ��������ʹ��delete����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;
	
	///6.5.3 ʹ�ͻ��˿�ʼ�뽻���й�ϵͳ�������ӣ����ӳɹ�����Խ��е�½��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init() = 0;
	
	///6.5.4 �ͻ��˵ȴ�һ���ӿ�ʵ���̵߳Ľ�����
	///@return �߳��˳�����
	virtual int Join() = 0;
	
	///6.5.5 ��õ�ǰ�����ա�ֻ�е��뽻���й�ϵͳ���ӽ�����Ż�ȡ����ȷ��ֵ��
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	virtual const char *GetTradingDay() = 0;
	
	///6.5.6 ע��һ��������CZQThostFtdcTraderSpi�ӿ����ʵ������ʵ��������¼�����
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///6.5.7 ���ý����й�ϵͳ������ͨѶ��ַ�������й�ϵͳӵ�ж��ͨ�ŵ�ַ�����û�ֻ��Ҫѡ��һ��ͨ�ŵ�ַ��
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CZQThostFtdcMdSpi *pSpi) = 0;
	
	///6.5.8 ����˽�������÷���Ҫ��Init ����ǰ���á����������򲻻��յ�˽���������ݡ�
	///@param nResumeType�� ˽�����ش���ʽ
	///        TERT_RESTART �ӱ������տ�ʼ�ش�
	///        TERT_RESUME ���ϴ��յ�������
	///        TERT_QUICK ֻ���͵�¼��˽����������
	//virtual void SubscribePrivateTopic(ZQTHOST_TE_RESUME_TYPE nResumeType) = 0;

	///6.5.9 ���Ĺ��������÷���Ҫ��Init ����ǰ���á����������򲻻��յ������������ݡ�
	//virtual void SubscribePublicTopic(ZQTHOST_TE_RESUME_TYPE nResumeType) = 0;

	///�������顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int SubscribeMarketData(char *ppInstrumentID[], int nCount, char* pExchageID) = 0;

	///�˶����顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int UnSubscribeMarketData(char *ppInstrumentID[], int nCount, char* pExchageID) = 0;

	///6.5.10 �û�������½����
	virtual int ReqUserLogin(CZQThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///6.5.11 �û������ǳ�����
	virtual int ReqUserLogout(CZQThostFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;

	/*///6.5.12 �û������޸�����
	virtual int ReqUserPasswordUpdate(CZQThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///6.5.13 �ʽ��˻������������
	virtual int ReqTradingAccountPasswordUpdate(CZQThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID) = 0;

	///6.5.14 �ͻ��˷�������¼������
	virtual int ReqOrderInsert(CZQThostFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///6.5.15 �ͻ��˷��������������󣬰��������ĳ����������Ĺ��𡢱����ļ���������޸ġ�
	virtual int ReqOrderAction(CZQThostFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///6.5.16 ��ѯ��󱨵���������
	virtual int ReqQueryMaxOrderVolume(CZQThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID) = 0;

	///6.5.17 Ͷ���߽�����ȷ�ϡ�
	virtual int ReqSettlementInfoConfirm(CZQThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID) = 0;

	///6.5.18 ���������ʽ�ת�ڻ���
	virtual int ReqTransferBankToFuture(CZQThostFtdcTransferHeaderField *pTransferHeader, CZQThostFtdcTransferBankToFutureReqField *pTransferBankToFutureReq, int nRequestID) = 0;

	///6.5.19 �����ڻ��ʽ�ת���С�
	virtual int ReqTransferFutureToBank(CZQThostFtdcTransferHeaderField *pTransferHeader, CZQThostFtdcTransferFutureToBankReqField *pTransferFutureToBankReq, int nRequestID) = 0;

	///6.5.20 �����ѯ�����ʽ�
	virtual int ReqTransferQryBank(CZQThostFtdcTransferHeaderField *pTransferHeader, CZQThostFtdcTransferQryBankReqField *pTransferQryBankReq, int nRequestID) = 0;

	///6.5.21 �����ѯ���н�����ϸ��
	virtual int ReqTransferQryDetail(CZQThostFtdcTransferHeaderField *pTransferHeader, CZQThostFtdcTransferQryDetailReqField *pTransferQryDetailReq, int nRequestID) = 0;

	///6.5.22 ������ѯ����
	virtual int ReqQryOrder(CZQThostFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///6.5.23 �ɽ�����ѯ����
	virtual int ReqQryTrade(CZQThostFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///6.5.24 ��Ա�ͻ���ѯ����
	virtual int ReqQryInvestor(CZQThostFtdcQryInvestorField *pQryInvestor, int nRequestID) = 0;

	///6.5.25 ��Ա�ֲֲ�ѯ����
	virtual int ReqQryInvestorPosition(CZQThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///6.5.26 �����ѯ�ʽ��˻���
	virtual int ReqQryTradingAccount(CZQThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID) = 0;

	///6.5.27 �����ѯ���ױ��롣
	virtual int ReqQryTradingCode(CZQThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID) = 0;

	///6.5.28 �����ѯ��������
	virtual int ReqQryExchange(CZQThostFtdcQryExchangeField *pQryExchange, int nRequestID) = 0;

	///6.5.29 �����ѯ��Լ��
	virtual int ReqQryInstrument(CZQThostFtdcQryInstrumentField *pQryInstrument,int nRequestID) = 0;*/

	///6.5.30 �����ѯ���顣
	//virtual int ReqQryDepthMarketData(CZQThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID) = 0;

	/*///6.5.31 �����ѯͶ���߽�������
	virtual int ReqQrySettlementInfo(CZQThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID) = 0;

	///6.5.32 �����ѯת�����С�
	virtual int ReqQryTransferBank(CZQThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID) = 0;

	///6.5.33 �����ѯͶ���ֲ߳���ϸ��
	virtual int ReqQryInvestorPositionDetail(CZQThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID) = 0;

	///6.5.34 �����ѯ�ͻ�֪ͨ��
	virtual int ReqQryNotice(CZQThostFtdcQryNoticeField *pQryNotice, int nRequestID) = 0;

	///6.5.35 ��ѯ������Ϣȷ�ϡ�
	virtual int ReqQrySettlementInfoConfirm(CZQThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID) = 0;

	///6.5.36 �����ѯǩԼ���С�
	virtual int ReqQryContractBank(CZQThostFtdcQryContractBankField *pQryContractBank, int nRequestID) = 0;

	///6.5.37 �����ѯԤ�񵥡�
	virtual int ReqQryParkedOrder(CZQThostFtdcQryParkedOrderField *pQryParkedOrder, int nRequestID) = 0;

	///6.5.38 �����ѯԤ�񳷵���
	virtual int ReqQryParkedOrderAction(CZQThostFtdcQryParkedOrderActionField *pQryParkedOrderAction, int nRequestID) = 0;

	///6.5.39 �����ѯͶ������ϳֲ���ϸ��
	virtual int ReqQryInvestorPositionCombineDetail(CZQThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID) = 0;

	///6.5.40 Ԥ��¼������
	virtual int ReqParkedOrderInsert (CZQThostFtdcParkedOrderField *pParkedOrder, int nRequestID) = 0;

	///6.5.41 Ԥ�񳷵�¼������
	virtual int ReqParkedOrderAction(CZQThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID) = 0;

	///6.5.42 ����ɾ��Ԥ�񵥡�
	virtual int ReqRemoveParkedOrder(CZQThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID) = 0;

	///6.5.43 ����ɾ��Ԥ�񳷵���
	virtual int ReqRemoveParkedOrderAction(CZQThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID) = 0;*/

protected:
	~CZQThostFtdcMdApi(){};
};

