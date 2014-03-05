#include "KCGameLayer.h"
#include "KCDirector.h"



bool KCGameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//백
	auto Back = Sprite::create("Image/Map/BackGround.png");
	Back->setAnchorPoint(ccp(0, 0));
	addChild(Back);

	//프론트
	Front = Sprite::create("Image/Map/FrontGround.png");
	Front->setAnchorPoint(ccp(0, 0));
	addChild(Front,5);

	//플레이어 
	MakePlayer();

	//장애물 어레이
	v_Trapes = CCArray::create();
	v_Trapes->retain();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(KCGameLayer::touchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(KCGameLayer::touchEnded, this);
	
	//마지막 인자는 터치 우선순위
	_eventDispatcher->addEventListenerWithFixedPriority(listener, 2);

	//메인루프
	this->schedule(schedule_selector(KCGameLayer::loop));

	//장애물 생성
	this->schedule(schedule_selector(KCGameLayer::MakeTrap), 1.3f);

	SetState(eGetReady);

	return true;
}

void KCGameLayer::FrontGroundUpdate()
{

	if (Front->getPositionX() <= -720)
		Front->setPositionX(0);
	else
		Front->setPositionX(Front->getPositionX() - GAMESPEED);

}

void KCGameLayer::loop(float dt)
{
	switch (m_eState)
	{
	case eGetReady:
		
		break;
	case ePlay:
		MainGameLoop(dt);
		break;
	case ePause:
		break;
	case eGameOver:
		break;
	default:
		break;
	}
	

}

bool KCGameLayer::touchBegan(Touch *touch, Event *event)
{
	return true;
}

void KCGameLayer::touchEnded(Touch *touch, Event *event)
{
	if (m_eState == ePlay)
	{
		if (p_mPlayer->GetState() != e_Down &&
			p_mPlayer->GetState() != e_Die)
		{
			p_mPlayer->SetJumpPower(JUMPPOWER);
			p_mPlayer->SetState(e_Jump);
		}
	}

	if (m_eState == eGetReady)
	{
		SetState(ePlay);
		p_mPlayer->SetJumpPower(JUMPPOWER);
		p_mPlayer->SetState(e_Jump);
	}

};

void KCGameLayer::MakeTrap(float dt)
{
	if (m_eState == ePlay)
	{
		auto Trap = KCTrap::create();
		addChild(Trap);
		v_Trapes->addObject(Trap);
	}
}

void KCGameLayer::TrapUpdate()
{
	CCObject * obj = NULL;
	CCARRAY_FOREACH(v_Trapes, obj)
	{
		KCTrap * Trap = (KCTrap*)obj;
		Trap->TrapUpdate();
		if (Trap->GetBisLife() == false)
		{
			removeChild(Trap);
			v_Trapes->removeObject(Trap);
		}
	}
}

void KCGameLayer::MainGameLoop(float dt)
{
	//플레이어 루프
	p_mPlayer->CrashUpdate(v_Trapes);
	p_mPlayer->StateUpdate(dt);
	if (p_mPlayer->GetState() == e_Die)
	{
		SetState(eGameOver);
	}

	if (p_mPlayer->GetState() != e_Down)
	{
		//앞 배경 업데이트
		FrontGroundUpdate();

		//장애물 업데이트
		TrapUpdate();

	}

}

void KCGameLayer::SetState(eGameLayerState val)
{
	switch (val)
	{
	case eGetReady:
		break;
	case ePlay:
		break;
	case ePause:
		break;
	case eGameOver:
		BeganGameOver();
		break;
	default:
		break;
	}

	m_eState = val;
}

void KCGameLayer::BeganGameOver()
{
	auto uiLayer = (KCUIlayer*)SceneMgr->GetScene()->getChildByTag(2);
	uiLayer->LayOutLoad();
}

void KCGameLayer::ReStart()
{
	//함정 전부 삭제
	CCObject * obj = NULL;
	CCARRAY_FOREACH(v_Trapes, obj)
	{
		removeChild((CCNode*)obj);
	}

	v_Trapes->removeAllObjects();

	//플레이어 삭제
	removeChild(p_mPlayer);
	//플레이어 생성
	MakePlayer();

	//앞배경 초기화
	Front->setPositionX(0);

	//스코어 초기화
	DataMgr->SetScore(0);

	//게임상태 초기화
	SetState(eGetReady);

}

void KCGameLayer::MakePlayer()
{
	p_mPlayer = KCPlayer::create();
	p_mPlayer->setPosition(ccp(SCREENX / 3, SCREENY / 3 * 2));
	p_mPlayer->SetWorldGravity(WGRAVITY);
	addChild(p_mPlayer, 6);
}
