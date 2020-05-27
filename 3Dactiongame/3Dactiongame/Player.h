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
		ANIM_DEFEND,
		ANIM_IDLE,
		ANIM_DIE,
		ANIM_JUMP,
		ANIM_JUMP_M,
		ANIM_CASTSPELL,
		ANIM_BACK,
		ANIM_BACK_M,
		ANIM_FORWARD,
		ANIM_FORWARD_M,
		ANIM_LEFT,
		ANIM_LEFT_M,
		ANIM_RIGHT,
		ANIM_RIGHT_M
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