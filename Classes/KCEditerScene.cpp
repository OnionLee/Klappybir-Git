#include "KCEditerScene.h"


cocos2d::Scene* KCEditerScene::createScene()
{
	auto scene = Scene::create();

	auto p_Layer = KCEditerScene::create();

	scene->addChild(p_Layer);

	return scene;
}

bool KCEditerScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}