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

	gravity = 0;	// �d��
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
}

//------------------------------------------------------
// @brief	����
//------------------------------------------------------
void Player::Behavior()
{
	moveSpeed = {};

	// ---------------
	// �Ƃ肠�����̂��
	moveSpeed.y += gravity;
	pos.y += moveSpeed.y;
	if (lpController.IsPushC(INPUT_TRG) && moveSpeed.y == 0.0f)
	{
		//moveSpeed.y += 100.0f;
		//jumpFlag = true;
	}
	// ---------------

	// ���͖���:�ҋ@���
	actionState = ACTION_STATE::ACTION_STATE_STANCE;

	moveFlag = false;

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

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_STANCE)
	{

	}

	// �E�ړ�
	if (lpController.IsPushRIGHT(INPUT_HOLD))
	{

		// �ړ����x
		moveSpeed.x = moveDir.x * 5.0f;
		moveSpeed.z = moveDir.z * 5.0f;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(moveSpeed.z, moveSpeed.y, -moveSpeed.x);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// ���ړ�
	if (lpController.IsPushLEFT(INPUT_HOLD))
	{
		// �ړ����x
		moveSpeed.x = moveDir.x * 5.0f;
		moveSpeed.z = moveDir.z * 5.0f;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(-moveSpeed.z, moveSpeed.y, moveSpeed.x);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// ��א��ʕ����Ɉړ�
	if (lpController.IsPushUP(INPUT_HOLD))
	{
		// �ړ����x
		moveSpeed.x = moveDir.x * 5.0f;
		moveSpeed.z = moveDir.z * 5.0f;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(moveSpeed.x, moveSpeed.y, moveSpeed.z);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// ��ׂ̕����Ɉړ�
	if (lpController.IsPushDOWN(INPUT_HOLD))
	{
		// �ړ����x
		moveSpeed.x = moveDir.x * 5.0f;
		moveSpeed.z = moveDir.z * 5.0f;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(-moveSpeed.x, moveSpeed.y, -moveSpeed.z);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// �ړ����Ă���Ƃ��̍X�V
	if (actionState == ACTION_STATE::ACTION_STATE_RUN)
	{
		rol.y = atan2(-moveSpeed.x, -moveSpeed.z);
		//pos.x += moveSpeed.x;
		//pos.z += moveSpeed.z;
		actionState = ACTION_STATE::ACTION_STATE_RUN;
		moveFlag = true;
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
	}

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