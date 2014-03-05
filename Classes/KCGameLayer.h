#pragma once
#include "cocos2d.h"


#include "KCPlayer.h"
#include "KCTrap.h"
#include <vector>

enum eGameLayerState
{
	eGetReady,
	ePlay,
	ePause,
	eGameOver,
};

using namespace cocos2d;


class KCGameLayer : public Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	void loop(float dt);

	void MainGameLoop(float dt);

	void TrapUpdate();

	void FrontGroundUpdate();
	

	bool touchBegan(Touch *touch, Event *event);
	void touchEnded(Touch *touch, Event *event);

	//장애물 생성 클래스
	void MakeTrap(float dt);

	void MakeScore(float dt);

	// implement the "static create()" method manually
	CREATE_FUNC(KCGameLayer);

	eGameLayerState GetState() const { return m_eState; }
	void SetState(eGameLayerState val);

	void BeganGameOver();

	void ReStart();

	void MakePlayer();

private:

	//플레이어
	KCPlayer * p_mPlayer;

	//앞에 배경
	Sprite * Front;

	//함정 배열
	Array * v_Trapes;

	//게임상태
	eGameLayerState m_eState;
};