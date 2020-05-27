//------------------------------------------------------
// @brief	ÌßÚ²Ô°‚ðŽB‚é¶Ò×
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <cmath>
#include "Vector3.h"
#include "Camera.h"
#include "ModelBase.h"

//------------------------------------------------------
// @brief	ºÝ½Ä×¸À
//------------------------------------------------------
Camera::Camera(ModelBase* m)
{
	model = m;
}

//------------------------------------------------------
// @brief	ÃÞ½Ä×¸À
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
	rotateSpeed = deg1Rad;
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
	
	// ¶Ò×‚ÌÎß¼Þ¼®Ý
	SetCameraPositionAndTargetAndUpVec(cameraPos.ConvertVec(),
											targetPos.ConvertVec(),
												cameraUpVec.ConvertVec());
												
}

//------------------------------------------------------
// @brief	¶Ò×‚ªŒü‚¢‚Ä‚¢‚é•ûŒü‚ð•Ô‚·
//------------------------------------------------------
Vector3 Camera::GetCameraDir()
{
	return cameraDir;
}