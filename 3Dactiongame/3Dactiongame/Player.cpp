//------------------------------------------------------
// @brief	��ڲ԰�𑀂�
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <vector>
#include <cmath>
#include <DxLib.h>
#include "ModelBase.h"
#include "Player.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Player::Player(int mID , std::vector<int>& aID)
	: ModelBase()
{
	modelID = MV1DuplicateModel(mID);
	for (int i = 0; i < aID.size(); i++) {
		animID.push_back(aID[i]);
	}
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
Player::~Player()
{
	// �ُ�I��������
	assert(modelID == NULL);
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void Player::Initialize()
{
	pos = {};
	rol = {};	// ����
	angle = 0.0f;
	// ��Ұ��ݾ�ı���
	animState = ANIM_IDLE;
	SetAnimID(modelID, ANIM_IDLE);
	oldAnimState = animState;
	playTime = 0;

	// ���ޯĂ̌v�Z
	// target = ConvertVec3(VTransform(VGet(300.0f, pos.y, pos.z), MGetRotY(rol.y)));
	//�u�g��k���v�u��]�v�u�ړ��v�̐ݒ�
	scl = Vector3(0.5f, 0.5f, 0.5f);
	MV1SetScale(modelID, scl.ConvertVec());//�A�g��k��
	MV1SetRotationXYZ(modelID, rol.ConvertVec());//��]
	// MV1SetRotationXYZ(model, rol);//��]
	MV1SetPosition(modelID, pos.ConvertVec());//�ړ�
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void Player::Finalize()
{
	// ���ق̍폜
	MV1DeleteModel(modelID);
	modelID = NULL;
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
	MV1DrawModel(modelID);
}

//------------------------------------------------------
// @brief	����
//------------------------------------------------------
void Player::Behavior(const Vector3& cameraDir)
{
	// ���͖���:�ҋ@���
	animState = ANIM_IDLE;

	// �ړ����x
	auto moveSpeed = cameraDir * 5.0f;

	// �E�ړ�
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(moveSpeed.z, moveSpeed.y, -moveSpeed.x);
		animState = ANIM_FORWARD;
	}

	// ���ړ�
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(-moveSpeed.z, moveSpeed.y, moveSpeed.x);
		animState = ANIM_FORWARD;
	}

	// ��א��ʕ����Ɉړ�
	if (CheckHitKey(KEY_INPUT_UP))
	{
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(moveSpeed.x, moveSpeed.y, moveSpeed.z);
		animState = ANIM_FORWARD;
	}

	// ��ׂ̕����Ɉړ�
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		// �i�ޕ����̑��x�ɕϊ�
		moveSpeed = Vector3(-moveSpeed.x, moveSpeed.y, -moveSpeed.z);
		animState = ANIM_FORWARD;
	}

	// �ړ����Ă���Ƃ��̍X�V
	if (animState == ANIM_FORWARD)
	{
		rol.y = atan2(-moveSpeed.x, -moveSpeed.z);
		pos.x += moveSpeed.x;
		pos.z += moveSpeed.z;
		animState = ANIM_FORWARD;
	}

	// �ړ��A��]�̐ݒ�
	MV1SetPosition(modelID, pos.ConvertVec());
	MV1SetRotationXYZ(modelID, rol.ConvertVec());
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
		SetAnimID(modelID, animState);
		// �ЂƂO�̱�Ұ��݂�ۑ�
		oldAnimState = animState;
	}

	playTime += 0.5f;
	if (playTime >= totalTime)
	{
		playTime = 0.0f;
	}

	// model�ɱ�Ұ��݂��
	MV1SetAttachAnimTime(modelID, attachiIndex, playTime);
}