#include "KCDirector.h"


KCDirector::KCDirector()
{
	m_pDataMgr = new KCDataMgr();
	m_pNetMgr = new KCNetworkMgr();
	m_pSceneMgr = new KCSceneMgr();
}


KCDirector::~KCDirector()
{
	delete m_pDataMgr;
	delete m_pNetMgr;
	delete m_pSceneMgr;
}
