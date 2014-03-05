#pragma once

#include "cocos2d.h"

USING_NS_CC;

#include "extensions/cocos-ext.h"
#include "gui/CocosGUI.h"
#include "editor-support/cocostudio/CCSGUIReader.h"



USING_NS_CC_EXT;
using namespace gui;

class KCUIlayer : public Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(KCUIlayer);


	void UpdateScroe(float dt);

	void LayOutLoad();

	void ReStart(Object* sender, TouchEventType type);

	void Rank(Object* sender, TouchEventType type);

private:
	gui::TextBMFont * m_pTextLable;
	
	Layout * GameOverPanal;

};

