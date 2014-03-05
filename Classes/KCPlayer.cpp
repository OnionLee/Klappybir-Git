#include "KCPlayer.h"
#include "KCTrap.h"


KCPlayer::KCPlayer()
{
	//월드의 중력치
	//매 프레임마다 버드의 위치에서 빼주는 값
	m_fWorldGravity = 0;

	//현재 버드에게 적용되고있는 힘
	m_fPower = 0;

	//버드에게 점프를 가할수 있게 하는 값 0이하로 갈 수 없다.
	m_fJumpPower = 0;
}


KCPlayer::~KCPlayer()
{
}

bool KCPlayer::init()
{
	if (!Sprite::initWithFile("Image/Bird/1.png"))
	{
		return false;
	}
	
	m_fStateUpdateTime = 0;

	SetState(e_Fly);

	return true;
}

void KCPlayer::StateUpdate(float dt)
{
	switch (m_eState)
	{
	case e_Null:
		break;
	case e_Die:
		StateDie();
		break;
	case e_Jump:
		StateJump();
		break;
	case e_Fly:
		StateFly();
		break;
	case e_Down:
		StateDown();
		break;
	default:
		break;
	}
	m_fStateUpdateTime += dt;
}

void KCPlayer::CrashUpdate(CCArray * p_Arr)
{
	if (GetState() == e_Down)
		return;
	if (GetState() == e_Die)
		return;

	CCObject * obj = NULL;
	CCARRAY_FOREACH(p_Arr, obj)
	{
		KCTrap * Trap = (KCTrap*)obj;
		if (Trap->GetTrap1BoundBox().intersectsRect(this->GetBoundBox())||
			Trap->GetTrap2BoundBox().intersectsRect(this->GetBoundBox()))
		{
			SetState(e_Down);
		}
	}
}

void KCPlayer::SetState(PlayerState val)
{
	switch (val)
	{
	case e_Null:
		break;
	case e_Die:
		break;
	case e_Jump:
		break;
	case e_Fly:
		break;
	default:
		break;
	}

	m_eState = val;
	m_fStateUpdateTime = 0;
}

bool KCPlayer::OnGravity()
{
	setPositionY(getPositionY() + m_fPower);

		setRotation(-m_fPower * 2);

	if (getPositionY() <= 320)
	{
		setPositionY(320);
		setRotation(90);
		SetState(e_Die);
		return false;
	}
	else
	{
		return true;
	}
}

void KCPlayer::StateDie()
{
	
}

void KCPlayer::StateDown()
{
	OnGravity();
	m_fPower -= m_fWorldGravity;
}

void KCPlayer::StateJump()
{
	OnGravity();

	m_fJumpPower -= m_fWorldGravity;
	m_fPower = m_fJumpPower;

	//점프가 최고지점에 도착했을때
	if (m_fPower < 0)
	{
		m_fJumpPower = 0;
		SetState(e_Fly);
	}
}

void KCPlayer::StateFly()
{
	OnGravity();

	m_fPower -= m_fWorldGravity;
}

cocos2d::Rect KCPlayer::GetBoundBox()
{
	Rect Box;

	Box.setRect(
		getPositionX() - (getContentSize().width / 2) ,
		getPositionY() - (getContentSize().height / 2),
		getContentSize().width,
		getContentSize().height
		);

	return Box;
}



