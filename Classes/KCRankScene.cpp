#include "KCRankScene.h"


cocos2d::Scene* KCRankScene::createScene()
{
	auto scene = Scene::create();

	auto p_Layer = KCRankScene::create();

	scene->addChild(p_Layer);

	return scene;
}

bool KCRankScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}
