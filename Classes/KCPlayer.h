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
	//�÷��̾��� ����
	PlayerState m_eState;

	//������ �߷�ġ
	//�� �����Ӹ��� ������ ��ġ���� ���ִ� ��
	float m_fWorldGravity;

	//���� ���忡�� ����ǰ��ִ� ��
	float m_fPower;

	//���忡�� ������ ���Ҽ� �ְ� �ϴ� �� 0���Ϸ� �� �� ����.
	float m_fJumpPower;

	//������Ʈ ������Ʈ Ÿ��
	float m_fStateUpdateTime;

};

