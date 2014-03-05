#include "KCGameLayer.h"
#include "KCDirector.h"



bool KCGameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//��
	auto Back = Sprite::create("Image/Map/BackGround.png");
	Back->setAnchorPoint(ccp(0, 0));
	addChild(Back);

	//����Ʈ
	Front = Sprite::create("Image/Map/FrontGround.png");
	Front->setAnchorPoint(ccp(0, 0));
	addChild(Front,5);

	//�÷��̾� 
	MakePlayer();

	//��ֹ� ���
	v_Trapes = CCArray::create();
	v_Trapes->retain();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(KCGameLayer::touchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(KCGameLayer::touchEnded, this);
	
	//������ ���ڴ� ��ġ �켱����
	_eventDispatcher->addEventListenerWithFixedPriority(listener, 2);

	//���η���
	this->schedule(schedule_selector(KCGameLayer::loop));

	//��ֹ� ����
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
	//�÷��̾� ����
	p_mPlayer->CrashUpdate(v_Trapes);
	p_mPlayer->StateUpdate(dt);
	if (p_mPlayer->GetState() == e_Die)
	{
		SetState(eGameOver);
	}

	if (p_mPlayer->GetState() != e_Down)
	{
		//�� ��� ������Ʈ
		FrontGroundUpdate();

		//��ֹ� ������Ʈ
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
	//���� ���� ����
	CCObject * obj = NULL;
	CCARRAY_FOREACH(v_Trapes, obj)
	{
		removeChild((CCNode*)obj);
	}

	v_Trapes->removeAllObjects();

	//�÷��̾� ����
	removeChild(p_mPlayer);
	//�÷��̾� ����
	MakePlayer();

	//�չ�� �ʱ�ȭ
	Front->setPositionX(0);

	//���ھ� �ʱ�ȭ
	DataMgr->SetScore(0);

	//���ӻ��� �ʱ�ȭ
	SetState(eGetReady);

}

void KCGameLayer::MakePlayer()
{
	p_mPlayer = KCPlayer::create();
	p_mPlayer->setPosition(ccp(SCREENX / 3, SCREENY / 3 * 2));
	p_mPlayer->SetWorldGravity(WGRAVITY);
	addChild(p_mPlayer, 6);
}
