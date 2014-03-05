#include "KCMainScene.h"
#include "KCDirector.h"


cocos2d::Scene* KCMainScene::createScene()
{
	auto scene = Scene::create();

	auto p_Layer = KCMainScene::create();

	scene->addChild(p_Layer);

	return scene;
}

bool KCMainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	
	return true;
}