#pragma once
#include "cocos2d.h"
using namespace cocos2d;

enum PlayerState{
	e_Null,
	e_Die,
	e_Down,
	e_Jump,
	e_Fly
};

class KCPlayer : public Sprite
{
public:
	KCPlayer();
	~KCPlayer();

	CREATE_FUNC(KCPlayer);

	virtual bool init();

	void StateUpdate(float dt);
	void StateDie();
	void StateJump();
	void StateDown();
	void StateFly();

	bool OnGravity();

	void CrashUpdate(CCArray * p_Arr);

	float GetWorldGravity() const { return m_fWorldGravity; }
	void SetWorldGravity(float val) { m_fWorldGravity = val; }

	float GetPower() const { return m_fPower; }
	void SetPower(float val) { m_fPower = val; }

	float GetJumpPower() const { return m_fJumpPower; }
	void SetJumpPower(float val) { m_fJumpPower = val; }

	PlayerState GetState() const { return m_eState; }
	void SetState(PlayerState val);

	cocos2d::Rect GetBoundBox();

private:
	//플레이어의 상태
	PlayerState m_eState;

	//월드의 중력치
	//매 프레임마다 버드의 위치에서 빼주는 값
	float m_fWorldGravity;

	//현재 버드에게 적용되고있는 힘
	float m_fPower;

	//버드에게 점프를 가할수 있게 하는 값 0이하로 갈 수 없다.
	float m_fJumpPower;

	//스테이트 업데이트 타임
	float m_fStateUpdateTime;

};

