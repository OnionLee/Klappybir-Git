#pragma once

#include "cocos2d.h"

#include "KCMainScene.h"
#include "KCGameScene.h"
#include "KCRankScene.h"
#include "KCEditerScene.h"

using namespace cocos2d;




enum eSceneSelector{
	eMainScene,
	eGameScene,
	eRankScene,
	eEditerScene
};

class KCSceneMgr
{
public:
	KCSceneMgr();
	~KCSceneMgr();

	//�� ����
	Scene * GetScene() const { return p_Scene; }
	void SetScene(Scene * val) { p_Scene = val; }

	//�� ��ȯ
	void SceneChanger(eSceneSelector selector);
private:
	Scene * p_Scene;

};

