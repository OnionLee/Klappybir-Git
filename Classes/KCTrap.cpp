#include "KCTrap.h"
#include "KCDirector.h"


KCTrap::KCTrap()
{
}


KCTrap::~KCTrap()
{
}

void KCTrap::TrapUpdate()
{
	setPositionX(getPositionX() - GAMESPEED);

	if (getPositionX() < -100)
	{
		//»ý¸íÁ×ÀÓ
		m_bisLife = false;
	}

	if (!m_bisScore)
		return;
	if ((int)getPositionX() < 250)
	{
		m_bisScore = false;
		DataMgr->SetScore(DataMgr->GetScore() + 1);
	}
}

bool KCTrap::init()
{


	p_Trap1 = Sprite::create("Image/Map/Trap1.png");
	p_Trap2 = Sprite::create("Image/Map/Trap2.png");

	p_Trap1->setPositionY(-640);
	p_Trap2->setPositionY(640);

	addChild(p_Trap1);
	addChild(p_Trap2);

	setPositionY((SCREENY / 2) + ((rand() % 5) * 50));
	setPositionX(800);

	m_bisLife = true;
	m_bisScore = true;



	return true;
}

cocos2d::Rect KCTrap::GetTrap1BoundBox()
{
	Rect Box;
	Box.setRect(
		getPositionX() - (p_Trap1->getContentSize().width / 2),
		getPositionY() - 160 - p_Trap1->getContentSize().height,
		p_Trap1->getContentSize().width,
		p_Trap1->getContentSize().height
		);

	return Box;
}

cocos2d::Rect KCTrap::GetTrap2BoundBox()
{
	Rect Box;
	Box.setRect(
		getPositionX() - (p_Trap1->getContentSize().width / 2),
		getPositionY() + 160,
		p_Trap1->getContentSize().width,
		p_Trap1->getContentSize().height
		);

	return Box;
}
