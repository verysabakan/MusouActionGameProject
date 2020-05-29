//------------------------------------------------------
// @brief	��ڲ԰�𑀂�
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

// �������ߐ錾
class ModelBase;

class Player 
	:public ModelBase
{
private:
	// ���݂̱�Ұ��݂̏�ԁAM:�ړ�
	enum ANIM_STATE
	{
		ANIM_DEAD,
		ANIM_DOWN,
		ANIM_DAMAGE,
		ANIM_STUN,
		ANIM_JUMP,
		ANIM_SKILL1,
		ANIM_SKILL2,
		ANIM_SKILL3,
		ANIM_ATTACK1,
		ANIM_ATTACK2,
		ANIM_BROCK,
		ANIM_WALK,
		ANIM_RUN,
		ANIM_STANCE
	};

	ANIM_STATE animState;
	ANIM_STATE oldAnimState;

public:
	Player(int mID , std::vector<int>& aID);
	~Player();
	void Initialize();	// ����������
	void Finalize();	// �I������
	void Update(const Vector3& cameraDir);		// �X�V
	void Render();		// �`��

private:
	void Behavior(const Vector3& cameraDir);		// ����
	void Animation();		// �ړ�
};