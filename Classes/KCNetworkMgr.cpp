#include "KCNetworkMgr.h"

//php 파일 목록
//KlappyGetHighScore.php
//KlappyGetHighScoreTable.php
//KlappyLogin.php
//KlappyRegister.php
//KlappySaveHighScore.php
KCNetworkMgr::KCNetworkMgr()
{
	m_sServerPath = "http://teamleaf.hubweb.net/KlappyBird/";
	
}


KCNetworkMgr::~KCNetworkMgr()
{

}


void KCNetworkMgr::KlappyGetHighScoreTable()
{

}

void KCNetworkMgr::KlappyLogin(const char * id, const char * passworld)
{
	std::string sURL = m_sServerPath + "?id=" + id + "&pass=" + passworld;
	m_pRequest = new HttpRequest;
	m_pRequest->setUrl(sURL.c_str());
	m_pRequest->setResponseCallback(this, callfuncND_selector(KCNetworkMgr::CallKlappyLogin));
}

void KCNetworkMgr::KlappyRegister(const char * id, const char * passworld)
{

}

void KCNetworkMgr::KlappySetHighScore(const char * score)
{

}

void KCNetworkMgr::KlappyGetHiqghScore(const char * score)
{

}

void KCNetworkMgr::NetWork_Update(float dt)
{

}

void KCNetworkMgr::CallKlappyLogin(Node * p_Sender, void * data)
{

}

void KCNetworkMgr::CallKlappyRegister(Node * p_Sender, void * data)
{

}

void KCNetworkMgr::CallKlappySetHighScore(Node * p_Sender, void * data)
{

}

void KCNetworkMgr::CallKlappyGetHiqghScore(Node * p_Sender, void * data)
{

}

void KCNetworkMgr::CallKlappyGetHighScoreTable(Node * p_Sender, void * data)
{

}
