#include <assert.h>
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
	//�A�j���[�V�����Z�b�g�A�b�v
	attachiIndex = MV1AttachAnim(modelID, 1, -1, false);
	//�A�j���[�V�����̃g�[�^�����Ԃ��v��
	totalTime = MV1GetAttachAnimTotalTime(modelID, attachiIndex);
	playTime = 0;
	newKey = 0;
	oldKey = 0;
	trgKey = 0;
	SetAnimID(modelID, 1);
	//�^�[�Q�b�g�̌v�Z
	target = VTransform(VGet(300.0f, pos.y, pos.z), MGetRotY(rol.y));
	//�u�g��k���v�u��]�v�u�ړ��v�̐ݒ�
	MV1SetScale(modelID, scl.ConvertVec());//�A�g��k��
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z));//��]
																				 //MV1SetRotationXYZ(model, rol);//��]
	MV1SetPosition(modelID, pos.ConvertVec());//�ړ�
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void Player::Finalize()
{

}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void Player::Update()
{

}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void Player::Render()
{

}