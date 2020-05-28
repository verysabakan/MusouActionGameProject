//------------------------------------------------------
// @brief	ÌßÚ²Ô°‚ğB‚é¶Ò×
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <cmath>
#include "Camera.h"
#include "ModelBase.h"

//------------------------------------------------------
// @brief	ºİ½Ä×¸À
//------------------------------------------------------
Camera::Camera(ModelBase* m)
{
	model = m;
}

//------------------------------------------------------
// @brief	ÃŞ½Ä×¸À
//------------------------------------------------------
Camera::~Camera()
{
	// ˆ—‚È‚µ
}

//------------------------------------------------------
// @brief	‰Šú‰»
//------------------------------------------------------
void Camera::Initialize()
{
	camLength = 500.0f;		//’†S‚©‚ç‚Ì‹——£
	cameraPos = { 0, 0, camLength };	// ¶Ò×‚Ì‰ŠúˆÊ’u
	targetPos = {};
	cameraDir = {};
	cameraUpVec = { 0, 1.0f, 0.0f };	// ¶Ò×‚Ìã•ûŒü
	cameraRol = {};
	quaternion.x = quaternion.y = quaternion.z = 0.0f;
	quaternion.t = 1.0f;
	camcnt = 0;
	deg = 90;
	//camRol = model->GetRotation();
	//camRol.y = (DX_PI_F / 180) * camDir;
	SetCameraNearFar(clipNear, clipFar);	// ¶Ò×‚Ì•`‰æ”ÍˆÍ
}

//------------------------------------------------------
// @brief	I—¹ˆ—
//------------------------------------------------------
void Camera::Finalize()
{

}

//------------------------------------------------------
// @brief	XV
//------------------------------------------------------
void Camera::Update()
{
	Vector3 rotate;	// ‰ñ“]‘¬“x
	cameraDir = (targetPos - cameraPos).Normalized();	// ¶Ò×‚ÌŒü‚«
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
	
	float roll = 0;		// roll‰ñ“]
	float pitch = 0;	// pitch‰ñ“]
	float yaw = 0;		// yaw‰ñ“]

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

	// Û°Ù
	auto zAxis = Vector3(mat.m[2][0], mat.m[2][1], mat.m[2][2]);
	quaternion = quaternion * CreateRotationQuaternion(roll, zAxis);

	// Ëß¯Á
	auto xAxis = Vector3(mat.m[0][0], mat.m[0][1], mat.m[0][2]);
	quaternion = quaternion * CreateRotationQuaternion(pitch, xAxis);

	// Ö°
	auto yAxis = Vector3(mat.m[1][0], mat.m[1][1], mat.m[1][2]);
	quaternion = quaternion * CreateRotationQuaternion(yaw, yAxis);

	Vector3 camPos = { 0, 0, camLength };	// Å‰‚Ì¶Ò×ˆÊ’u

	matRot = MMult(matRot, QuaternionToMatrix(quaternion));

	auto DL = camPos * matRot;

	auto camZAxis = Vector3(matRot.m[2][0], matRot.m[2][1], matRot.m[2][2]);

	auto rotAxis = Cross(camPos, camZAxis);

	auto transQ = CreateRotationQuaternion(roll, rotAxis);

	auto TransRotMat = QuaternionToMatrix(transQ);

	camPos = camPos * TransRotMat;

	//matRot = QuaternionToMatrix(quaternion);
	//mat = MMult(mat, matRot);         //‰ñ“]~½¹°Ù

	//matTrans = MGetTranslate(VGet(0, 0, 0));
	//mat = MMult(mat, matTrans);       //ˆÚ“®~‰ñ“]~½¹°Ù

	//cameraPos = cameraPos * mat;
	///////////////////////////////////////////

	// ¶Ò×İ’è
	SetCameraPositionAndTargetAndUpVec(cameraPos.ConvertVec(), targetPos.ConvertVec(), cameraUpVec.ConvertVec());
}

//------------------------------------------------------
// @brief	¶Ò×‚ªŒü‚¢‚Ä‚¢‚é•ûŒü‚ğ•Ô‚·
//------------------------------------------------------
Vector3 Camera::GetCameraDir()
{
	return cameraDir;
}