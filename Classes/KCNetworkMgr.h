#pragma once
#include <iostream>
#include <string>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "network/HttpClient.h"

using namespace cocos2d::extension;
using namespace cocos2d::network;
using namespace cocos2d;


struct sUserData{
	char m_cScore[16];
	char m_cName[32];
};

class KCNetworkMgr
{
public:
	std::string m_sServerPath;

	void KlappyLogin(const char * id, const char * passworld);
	void KlappyRegister(const char * id, const char * passworld);
	void KlappySetHighScore(const char * score);
	void KlappyGetHiqghScore(const char * score);
	void KlappyGetHighScoreTable();

	void CallKlappyLogin(Node * p_Sender, void * data);
	void CallKlappyRegister(Node * p_Sender, void * data);
	void CallKlappySetHighScore(Node * p_Sender, void * data);
	void CallKlappyGetHiqghScore(Node * p_Sender, void * data);
	void CallKlappyGetHighScoreTable(Node * p_Sender, void * data);



	Node * GetTarget() const { return m_pTarget; }
	void SetTarget(Node * val) { m_pTarget = val; }

	void NetWork_Update(float dt);

private:

	HttpRequest * m_pRequest;
	Node * m_pTarget;

	KCNetworkMgr();
	~KCNetworkMgr();
};

