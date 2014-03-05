#include "KCGameScene.h"


cocos2d::Scene* KCGameScene::createScene()
{
	auto scene = Scene::create();

	auto p_Layer1 = KCGameLayer::create();
	auto p_Layer2 = KCUIlayer::create();

	scene->addChild(p_Layer1,1,1);
	scene->addChild(p_Layer2,2,2);

	return scene;
}