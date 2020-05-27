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
	camLength = 500.0f;		//���S����̋���
	cameraPos = { 0, 0, camLength };	// ��ׂ̏����ʒu
	targetPos = {};
	cameraDir = {};
	cameraUpVec = { 0, 1.0f, 0.0f };	// ��ׂ̏����
	cameraRol = {};
	rotateSpeed = deg1Rad;
	camcnt = 0;
	deg = 90;
	//camRol = model->GetRotation();
	//camRol.y = (DX_PI_F / 180) * camDir;
	SetCameraNearFar(clipNear, clipFar);	// ��ׂ̕`��͈�
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
	Vector3 rotate;	// ��]���x
	cameraDir = (targetPos - cameraPos).Normalized();	// ��ׂ̌���

	if (CheckHitKey(KEY_INPUT_F)) { camLength += 5; }
	if (CheckHitKey(KEY_INPUT_G)) { camLength -= 5; }
	
	if (CheckHitKey(KEY_INPUT_W))
	{
		if (cameraDir.y >= deg1Rad * -70)
		{
			rotate.x = -rotateSpeed;
		}
	}

	if (CheckHitKey(KEY_INPUT_S)) 
	{ 
		if (cameraDir.y <= deg1Rad * 70)
		{
			rotate.x = rotateSpeed;
		}
	}

	if (CheckHitKey(KEY_INPUT_A)) { rotate.y = rotateSpeed; }
	if (CheckHitKey(KEY_INPUT_D)) { rotate.y = -rotateSpeed; }
	
	// ---------------------------------
	/*MATRIX viewMatrix;
	viewMatrix = MGetIdent();
	memcpy(viewMatrix.m[0], &Vector3(1, 0, 0), sizeof(Vector3));
	memcpy(viewMatrix.m[1], &Vector3(0, 1, 0), sizeof(Vector3));
	memcpy(viewMatrix.m[2], &Vector3(0, 0, 1), sizeof(Vector3));

	Vector3 camPos = { 0, 0, -100 };

	auto z = MGetRotZ(angle.z);

	auto xyz = MMult(z, y);
	xyz = MMult(xyz, x);

	CreateLookAtMatrix(&viewMatrix, &cameraPos.ConvertVec(),
			&targetPos.ConvertVec(), &cameraUpVec.ConvertVec());

	Vector3 D = { 1, 1, 0 };
	
	auto vecView = D * viewMatrix;

	auto camZAxis = Vector3(viewMatrix.m[2][0], viewMatrix.m[2][1], viewMatrix.m[2][2]);

	auto TransQ =*/ 

	// ---------------------------------
	
	// ��ׂ��߼޼��
	SetCameraPositionAndTargetAndUpVec(cameraPos.ConvertVec(),
											targetPos.ConvertVec(),
												cameraUpVec.ConvertVec());
												
}

//------------------------------------------------------
// @brief	��ׂ������Ă��������Ԃ�
//------------------------------------------------------
Vector3 Camera::GetCameraDir()
{
	return cameraDir;
}