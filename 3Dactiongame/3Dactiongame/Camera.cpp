//------------------------------------------------------
// @brief	��ڲ԰���B����
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <cmath>
#include "Vector3.h"
#include "Camera.h"
#include "ModelBase.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Camera::Camera(ModelBase* m)
{
	model = m;
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
Camera::~Camera()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void Camera::Initialize()
{
	cameraPos = Vector3(0.0f, 50.0f, -500.0f);
	targetPos = Vector3(0.0f, 0.0f, 0.0f);
	cameraUpVec = Vector3(0.0f, 1.0f, 0.0f);
	yaw = DX_PI_F / 60;
	camLength = 500.0f;		//���S����̋���
	camDir = 90.0f;
	camcnt = 0;
	//camDir = 5;
	deg = 90;
	camRol = Vector3(0.0f, 0.0f, 0.0f);
	camRol.y = (DX_PI_F / 180)*camDir;
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void Camera::Finalize()
{

}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void Camera::Update()
{
	if (CheckHitKey(KEY_INPUT_F))
	{
		camLength += 5;
	}
	if (CheckHitKey(KEY_INPUT_G))
	{
		camLength -= 5;
	}

	//�v�Z�p�̍��W���ق�p�ӂ���
	auto modelPos = model->GetPosition();

	camRol = model->GetRotation();
	targetPos.x = modelPos.x + cosf(camRol.y) * 300.0f;
	targetPos.z = modelPos.z - sinf(camRol.y) * 300.0f;
	targetPos.y = 50.0f;

	// ���ޯĂւ��޸�ٕϊ�
	auto camVec = ConvertVec3(VGet(targetPos.x - modelPos.x,
										targetPos.y,
											targetPos.z - modelPos.z));
	
	// �޸�ق̐��K��
	camVec = camVec.Normalized();	//�P���޸��

	// �޸�ٕ����ֵ̾�Ă���
	cameraPos.x = modelPos.x - camVec.x*camLength;
	cameraPos.y = modelPos.y + (camVec.y*camLength + standardEye);	//100.0f�͕W���ڐ�
	cameraPos.z = modelPos.z - camVec.z*camLength;

	//�J�����|�W�V����
	SetCameraPositionAndTargetAndUpVec(cameraPos.ConvertVec(),
											targetPos.ConvertVec(),
												cameraUpVec.ConvertVec());
}