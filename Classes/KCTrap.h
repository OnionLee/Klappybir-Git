#pragma once

#include "cocos2d.h"
using namespace cocos2d;

class KCTrap : public CCNode
{
public:
	KCTrap();
	~KCTrap();

	virtual bool init();

	void TrapUpdate();

	CREATE_FUNC(KCTrap);

	cocos2d::Rect GetTrap1BoundBox();
	cocos2d::Rect GetTrap2BoundBox();

	bool GetBisLife() const { return m_bisLife; }

private:
	Sprite * p_Trap1;
	Sprite * p_Trap2;

	bool m_bisLife;
	bool m_bisScore;


};

