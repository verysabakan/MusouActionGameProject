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
	animState = ANIM_STANCE;
	SetAnimID(modelHandle, animState);
	oldAnimState = animState;	// �O�̱�Ұ���
	playTime = 0;
	// ���ޯĂ̌v�Z
	// target = ConvertVec3(VTransform(VGet(300.0f, pos.y, pos.z), MGetRotY(rol.y)));
	//�u�g��k���v�u��]�v�u�ړ��v�̐ݒ�
	scl = Vector3(0.5f, 0.5f, 0.5f);
	MV1SetScale(modelHandle, scl.ConvertVec());//�A�g��k��
	MV1SetRotationXYZ(modelHandle, rol.ConvertVec());//��]
	// MV1SetRotationXYZ(model, rol);//��]
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
void Player::Update(const Vector3& cameraDir)
{
	// �ړ��̍X�V
	Behavior(cameraDir);
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
void Player::Behavior(const Vector3& cameraDir)
{
	moveSpeed = {};

	// ---------------
	// �Ƃ肠�����̂��
	moveSpeed.y += gravity;
	//pos.y += moveSpeed.y;
	if (lpController.IsPushC(INPUT_TRG) && moveSpeed.y == 0.0f)
	{
		moveSpeed.y = 30.0f;
		jumpFlag = true;
	}
	// ---------------

	// ���͖���:�ҋ@���
	animState = ANIM_STANCE;

	moveFlag = false;

	// �s���ʂ̏���(�D��x��)
	if (animState == ANIM_DEAD)
	{
		
	}
	else if (animState == ANIM_DOWN)
	{

	}
	else if (animState == ANIM_DAMAGE)
	{

	}
	else if (animState == ANIM_STUN)
	{

	}
	else if (animState == ANIM_JUMP)
	{
		
	}
	else if (animState == ANIM_SKILL1)
	{

	}
	else if (animState == ANIM_SKILL2)
	{

	}
	else if (animState == ANIM_SKILL3)
	{

	}
	else if (animState == ANIM_ATTACK1)
	{
		
	}
	else if (animState == ANIM_ATTACK2)
	{

	}
	else if (animState == ANIM_BROCK)
	{

	}
	else if (animState == ANIM_WALK)
	{

	}
	else if (animState == ANIM_RUN)
	{

	}
	else if (animState == ANIM_STANCE)
	{

	}

	// �E�ړ�
	if (lpController.IsPushRIGHT(INPUT_HOLD))
	{

		// �ړ����x
		moveSpeed.x = cameraDir.x * 5.0f;
		moveSpeed.z = cameraDir.z * 5.0f;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(moveSpeed.z, moveSpeed.y, -moveSpeed.x);
		animState = ANIM_RUN;
	}

	// ���ړ�
	if (lpController.IsPushLEFT(INPUT_HOLD))
	{
		// �ړ����x
		moveSpeed.x = cameraDir.x * 5.0f;
		moveSpeed.z = cameraDir.z * 5.0f;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(-moveSpeed.z, moveSpeed.y, moveSpeed.x);
		animState = ANIM_RUN;
	}

	// ��א��ʕ����Ɉړ�
	if (lpController.IsPushUP(INPUT_HOLD))
	{
		// �ړ����x
		moveSpeed.x = cameraDir.x * 5.0f;
		moveSpeed.z = cameraDir.z * 5.0f;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(moveSpeed.x, moveSpeed.y, moveSpeed.z);
		animState = ANIM_RUN;
	}

	// ��ׂ̕����Ɉړ�
	if (lpController.IsPushDOWN(INPUT_HOLD))
	{
		// �ړ����x
		moveSpeed.x = cameraDir.x * 5.0f;
		moveSpeed.z = cameraDir.z * 5.0f;
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(-moveSpeed.x, moveSpeed.y, -moveSpeed.z);
		animState = ANIM_RUN;
	}

	// �ړ����Ă���Ƃ��̍X�V
	if (animState == ANIM_RUN)
	{
		rol.y = atan2(-moveSpeed.x, -moveSpeed.z);
		//pos.x += moveSpeed.x;
		//pos.z += moveSpeed.z;
		animState = ANIM_RUN;
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
	if (animState != oldAnimState)
	{
		// ��Ұ��݂̐؂�ւ�
		SetAnimID(modelHandle, animState);
		// �ЂƂO�̱�Ұ��݂�ۑ�
		oldAnimState = animState;
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
// @brief	��Ұ���
//------------------------------------------------------
ObjectType Player::GetType()
{
	return ObjectType::OBJECTTYPE_PLAYER;
}