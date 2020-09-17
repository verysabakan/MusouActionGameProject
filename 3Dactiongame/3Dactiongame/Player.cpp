//------------------------------------------------------
// @brief	��ڲ԰�𑀂�
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <vector>
#include <cmath>
#include <DxLib.h>
#include "Player.h"
#include "Controller.h"

#include "FrameRate.h"
#include "_Debug.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Player::Player(int mID , std::vector<int>& aID)
{
	// ���ق�ǂݍ��݁A����
	modelHandle = MV1DuplicateModel(mID);
	for (int i = 0; i < aID.size(); i++)
	{
		animHandle.push_back(aID[i]);
	}
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
Player::~Player()
{
	// �ُ�I��������
	assert(modelHandle == NULL);
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void Player::Initialize()
{
	pos = {4557, 0, 2782};
	// ��Ұ��ݾ�ı���
	actionState = ACTION_STATE::ACTION_STATE_STANCE;
	SetAnimID(modelHandle, actionState);
	oldActionState = actionState;	// �O�̱�Ұ���
	playTime = 0;
	//�u�g��k���v�u��]�v�u�ړ��v�̐ݒ�
	scl = Vector3(0.5f, 0.5f, 0.5f);
	MV1SetScale(modelHandle, scl.ConvertVec());//�A�g��k��
	MV1SetRotationXYZ(modelHandle, rol.ConvertVec());//��]
	MV1SetPosition(modelHandle, pos.ConvertVec());//�ړ�

}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void Player::Finalize()
{
	// ���ق̍폜
	MV1DeleteModel(modelHandle);
	modelHandle = NULL;
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void Player::Update()
{
	// �ړ��̍X�V
	Behavior();
	// ��Ұ��݂̍X�V
	Animation();
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void Player::Render()
{
	// �`��
	MV1DrawModel(modelHandle);

	// ���ޯ�ނ̎������`��
#ifdef _DEBUG
	DebugDrawStart;
	DFS(500, 0, 0xffffff, "%f,%f,%f", rol.x, rol.y, rol.z);
	DFS(500, 16, 0xffffff, "%f,%f,%f", moveSpeed.x, moveSpeed.y, moveSpeed.z);
	DebugDrawEnd;
#endif // _DEBUG
}
//------------------------------------------------------
// @brief	����
//------------------------------------------------------
void Player::Behavior()
{
	auto newSpeed = Vector3();
	
	// ---------------
	// �Ƃ肠�����̂��
	if (lpController->IsPushC(INPUT_STATE::INPUT_TRG) && actionState != ACTION_STATE::ACTION_STATE_JUMP)
	{
		moveSpeed.y = 5.0f;
		actionState = ACTION_STATE::ACTION_STATE_JUMP;
	}
	if (lpController->IsPushA(INPUT_STATE::INPUT_TRG))
	{
		actionState = ACTION_STATE::ACTION_STATE_ATTACK1;
	}
	// ---------------

	// ��א��ʕ����Ɉړ�
	if (lpController->IsPushUP(INPUT_STATE::INPUT_HOLD))
	{
		// �ړ����x
		newSpeed = moveDir * 5.0f;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = moveSpeed + newSpeed;
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// ��ׂ̕����Ɉړ�
	if (lpController->IsPushDOWN(INPUT_STATE::INPUT_HOLD))
	{
		// �ړ����x
		newSpeed = moveDir * 5.0f * -1.0f;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = moveSpeed + newSpeed;
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// �E�ړ�
	if (lpController->IsPushRIGHT(INPUT_STATE::INPUT_HOLD))
	{
		// �ړ����x
		newSpeed = moveDir * 5.0f;
		moveSpeed = moveSpeed + newSpeed;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(moveSpeed.z, moveSpeed.y, -moveSpeed.x);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// ���ړ�
	if (lpController->IsPushLEFT(INPUT_STATE::INPUT_HOLD))
	{
		// �ړ����x
		newSpeed = moveDir * 5.0f;
		moveSpeed = moveSpeed + newSpeed;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(-moveSpeed.z, moveSpeed.y, moveSpeed.x);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// �s���ʂ̏���(�D��x��)
	if (actionState == ACTION_STATE::ACTION_STATE_DEAD)
	{
		
	}
	else if (actionState == ACTION_STATE::ACTION_STATE_DOWN)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_DAMAGE)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_STUN)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_JUMP)
	{
		moveSpeed -= otamesi * lpFrameRate->GetStepTime();
		moveSpeed.y += -9.8f * lpFrameRate->GetStepTime();
	}
	else if (actionState == ACTION_STATE::ACTION_STATE_SKILL1)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_SKILL2)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_SKILL3)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_ATTACK1)
	{
		if (playTime >= totalTime)
		{
			actionState = ACTION_STATE::ACTION_STATE_STANCE;
		}
	}
	else if (actionState == ACTION_STATE::ACTION_STATE_ATTACK2)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_BROCK)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_WALK)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_RUN)
	{
		rol.y = atan2(-moveSpeed.x, -moveSpeed.z);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}
	else if (actionState == ACTION_STATE::ACTION_STATE_STANCE)
	{

	}

	// �ړ��A��]�̐ݒ�
	MV1SetPosition(modelHandle, pos.ConvertVec());
	MV1SetRotationXYZ(modelHandle, rol.ConvertVec());
}

//------------------------------------------------------
// @brief	��Ұ���
//------------------------------------------------------
void Player::Animation()
{
	// �O�ƈ���Ă�����X�V����
	if (actionState != oldActionState)
	{
		// ��Ұ��݂̐؂�ւ�
		SetAnimID(modelHandle, actionState);
		// �ЂƂO�̱�Ұ��݂�ۑ�
		oldActionState = actionState;
	}

	// ��Ұ��݂̍Đ�
	playTime += 0.5f;
	if (playTime >= totalTime)
	{
		playTime = 0.0f;
		if (actionState == ACTION_STATE::ACTION_STATE_ATTACK1)
		{
			actionState = ACTION_STATE::ACTION_STATE_STANCE;
		}
	}

	otamesi = ConvertVec3(MV1GetAttachAnimFrameLocalPosition(modelHandle, attachiIndex, 0));
	// model�ɱ�Ұ��݂��
	MV1SetAttachAnimTime(modelHandle, attachiIndex, playTime);
}

//------------------------------------------------------
// @brief	��޼ު�Ă̎�ނ��擾
//------------------------------------------------------
OBJECT_TYPE Player::GetType()
{
	return OBJECT_TYPE::OBJECT_TYPE_PLAYER;
}