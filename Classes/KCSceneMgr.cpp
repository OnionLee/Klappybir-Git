#include "KCSceneMgr.h"


KCSceneMgr::KCSceneMgr()
{
}


KCSceneMgr::~KCSceneMgr()
{
}

void KCSceneMgr::SceneChanger(eSceneSelector selector)
{
	Scene * s;
	TransitionFade* fade;

	switch (selector)
	{
	case eMainScene:
		s = KCMainScene::createScene();
		fade = TransitionFade::create(1.0f, s, Color3B::WHITE);
		Director::getInstance()->replaceScene(fade);
		break;
	case eGameScene:
		s = KCGameScene::createScene();
		fade = TransitionFade::create(1.0f, s, Color3B::WHITE);
		Director::getInstance()->replaceScene(fade);
		break;
	case eRankScene:
		s = KCRankScene::createScene();
		fade = TransitionFade::create(1.0f, s, Color3B::WHITE);
		Director::getInstance()->replaceScene(fade);
		break;
	case eEditerScene:
		s = KCEditerScene::createScene();
		fade = TransitionFade::create(1.0f, s, Color3B::WHITE);
		Director::getInstance()->replaceScene(fade);
		break;
	default:
		break;
	}

	p_Scene = s;
}
