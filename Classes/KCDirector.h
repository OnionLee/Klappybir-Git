#pragma once
#include "Singleton.h"

#include "KCDataMgr.h"
#include "KCNetworkMgr.h"
#include "KCSceneMgr.h"

#define SCREENY CCDirector::getInstance()->getWinSize().height
#define SCREENX CCDirector::getInstance()->getWinSize().width

#define GAMESPEED 6
#define JUMPPOWER 16
#define WGRAVITY (float)(CCDirector::getInstance()->getWinSize().height / 1400.0f)

class KCDirector : public CSingleton<KCDirector>
{
public:
	KCDirector();
	~KCDirector();

	KCDataMgr * GetDataMgr() const { return m_pDataMgr; }
	void SetDataMgr(KCDataMgr * val) { m_pDataMgr = val; }

	KCNetworkMgr * GetNetMgr() const { return m_pNetMgr; }
	void SetNetMgr(KCNetworkMgr * val) { m_pNetMgr = val; }

	KCSceneMgr * GetSceneMgr() const { return m_pSceneMgr; }
	void SetSceneMgr(KCSceneMgr * val) { m_pSceneMgr = val; }

private:
	KCDataMgr * m_pDataMgr;

	KCNetworkMgr * m_pNetMgr;

	KCSceneMgr * m_pSceneMgr;
};

#define DataMgr KCDirector::GetSingleton()->GetDataMgr()
#define NetWorkMgr KCDirector::GetSingleton()->GetNetMgr()
#define SceneMgr KCDirector::GetSingleton()->GetSceneMgr()