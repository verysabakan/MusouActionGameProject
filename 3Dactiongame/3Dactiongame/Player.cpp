#include <assert.h>
#include <cmath>
#include <DxLib.h>
#include "ModelBase.h"
#include "Player.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Player::Player(int ID)
	: ModelBase()
{
	modelID = MV1DuplicateModel(ID);
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
	pos = Vector3();
	rol = Vector3();
	scl = Vector3(0.5f, 0.5f, 0.5f);
	dir = 0.0f;
	// ��Ұ��ݾ�ı���
	attachiIndex = MV1AttachAnim(modelID, 1, -1, false);
	// ��Ұ��݂�İ�َ��Ԃ��v��
	totalTime = MV1GetAttachAnimTotalTime(modelID, attachiIndex);
	playTime = 0;
	newKey = 0;
	oldKey = 0;
	trgKey = 0;
	SetAnimID(modelID, 1);
	// ���ޯĂ̌v�Z
	target = ConvertVec3(VTransform(VGet(300.0f, pos.y, pos.z), MGetRotY(rol.y)));
	//�u�g��k���v�u��]�v�u�ړ��v�̐ݒ�
	MV1SetScale(modelID, scl.ConvertVec());//�A�g��k��
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z));//��]
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
void Player::Update()
{
	newKey = 0;
	//���E����
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		dir += 0.8f;
		newKey = 1;
		//ModelAnimTime(ACT_RUN);
	}


	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		dir -= 0.8f;
		newKey = 1;
	}
	rol.y = (DX_PI_F / 180)*dir;// ׼ޱ݂ɕϊ�
	//----�����Ă�������ɑO��ړ�
	if (CheckHitKey(KEY_INPUT_UP))
	{
		pos.x += cosf(rol.y)*3.0f;
		pos.z -= sinf(rol.y)*3.0f;
		newKey = 1;
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		pos.x -= cosf(rol.y)*3.0f;
		newKey = 1;
		pos.z += sinf(rol.y)*3.0f;
	}

	// ���ޯĂ̌v�Z
	target = ConvertVec3(VTransform(VGet(300.0f, 0.0f, 0.0f), MGetRotY(rol.y)));
	//�u�g��k���v�u��]�v�u�ړ��v�̐ݒ�
	MV1SetScale(modelID, scl.ConvertVec());// �A�g��k��2
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z)); //��]
	// MV1SetRotationXYZ(model, rol);// ��]
	MV1SetPosition(modelID, pos.ConvertVec());// �ړ�

	// ��Ұ��݂̐؂�ւ�
	if ((newKey == 1) && oldKey == 0)
	{
		SetAnimID(modelID, 7);

	}
	if ((newKey == 0) && oldKey == 1)
	{
		// ��~(0��)Ӱ��݂��
		// ����(7��)Ӱ��݂��
		SetAnimID(modelID, 1);
	}
	oldKey = newKey;// ����ٰ�߂ׂ̈̏���
	playTime += 0.5f;
	if (playTime >= totalTime)
	{
		playTime = 0.0f;
	}
	// model�ɱ�Ұ��݂��
	MV1SetAttachAnimTime(modelID, attachiIndex, playTime);
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void Player::Render()
{
	// �`��
	MV1DrawModel(modelID);
}