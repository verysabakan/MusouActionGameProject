//------------------------------------------------------
// @brief	��ڲ԰���B����
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <cmath>
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
	quaternion.x = quaternion.y = quaternion.z = 0.0f;
	quaternion.t = 1.0f;
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
	auto modelPos = model->GetPosition();
	cameraPos += modelPos - targetPos;
	targetPos = modelPos;

	if (CheckHitKey(KEY_INPUT_F)) 
	{ 
		camLength += 5; 
	}

	if (CheckHitKey(KEY_INPUT_G)) 
	{ 
		camLength -= 5;
	}
	
	float roll = 0;		// roll��]
	float pitch = 0;	// pitch��]
	float yaw = 0;		// yaw��]

	if (CheckHitKey(KEY_INPUT_W))
	{
		roll = deg1Rad;
	}

	if (CheckHitKey(KEY_INPUT_S)) 
	{
		roll = -deg1Rad;
	}

	if (CheckHitKey(KEY_INPUT_A)) 
	{ 
		yaw = deg1Rad;
	}

	if (CheckHitKey(KEY_INPUT_D)) 
	{ 
		yaw = -deg1Rad;
	}

	/////////////////////////////////////
	MATRIX mat;
	MATRIX matRot;
	MATRIX matTrans;
	CreateIdentityMatrix(&mat);
	CreateIdentityMatrix(&matRot);

	quaternion.x = quaternion.y = quaternion.z = 0.0f;
	quaternion.t = 1.0f;

	// ۰�
	auto zAxis = Vector3(mat.m[2][0], mat.m[2][1], mat.m[2][2]);
	quaternion = quaternion * CreateRotationQuaternion(roll, zAxis);

	// �߯�
	auto xAxis = Vector3(mat.m[0][0], mat.m[0][1], mat.m[0][2]);
	quaternion = quaternion * CreateRotationQuaternion(pitch, xAxis);

	// ְ
	auto yAxis = Vector3(mat.m[1][0], mat.m[1][1], mat.m[1][2]);
	quaternion = quaternion * CreateRotationQuaternion(yaw, yAxis);

	Vector3 camPos = { 0, 0, camLength };	// �ŏ��̶�׈ʒu

	matRot = MMult(matRot, QuaternionToMatrix(quaternion));

	auto DL = camPos * matRot;

	auto camZAxis = Vector3(matRot.m[2][0], matRot.m[2][1], matRot.m[2][2]);

	auto rotAxis = Cross(camPos, camZAxis);

	auto transQ = CreateRotationQuaternion(roll, rotAxis);

	auto TransRotMat = QuaternionToMatrix(transQ);

	camPos = camPos * TransRotMat;

	//matRot = QuaternionToMatrix(quaternion);
	//mat = MMult(mat, matRot);         //��]�~����

	//matTrans = MGetTranslate(VGet(0, 0, 0));
	//mat = MMult(mat, matTrans);       //�ړ��~��]�~����

	//cameraPos = cameraPos * mat;
	///////////////////////////////////////////

	// ��אݒ�
	SetCameraPositionAndTargetAndUpVec(cameraPos.ConvertVec(), targetPos.ConvertVec(), cameraUpVec.ConvertVec());
}

//------------------------------------------------------
// @brief	��ׂ������Ă��������Ԃ�
//------------------------------------------------------
Vector3 Camera::GetCameraDir()
{
	return cameraDir;
}