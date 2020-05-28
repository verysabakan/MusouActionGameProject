//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを撮るｶﾒﾗ
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <cmath>
#include "Camera.h"
#include "ModelBase.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
Camera::Camera(ModelBase* m)
{
	model = m;
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
Camera::~Camera()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void Camera::Initialize()
{
	camLength = 500.0f;		//中心からの距離
	cameraPos = { 0, 0, camLength };	// ｶﾒﾗの初期位置
	targetPos = {};
	cameraDir = {};
	cameraUpVec = { 0, 1.0f, 0.0f };	// ｶﾒﾗの上方向
	cameraRol = {};
	quaternion.x = quaternion.y = quaternion.z = 0.0f;
	quaternion.t = 1.0f;
	camcnt = 0;
	deg = 90;
	//camRol = model->GetRotation();
	//camRol.y = (DX_PI_F / 180) * camDir;
	SetCameraNearFar(clipNear, clipFar);	// ｶﾒﾗの描画範囲
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void Camera::Finalize()
{

}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void Camera::Update()
{
	Vector3 rotate;	// 回転速度
	cameraDir = (targetPos - cameraPos).Normalized();	// ｶﾒﾗの向き
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
	
	float roll = 0;		// roll回転
	float pitch = 0;	// pitch回転
	float yaw = 0;		// yaw回転

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

	// ﾛｰﾙ
	auto zAxis = Vector3(mat.m[2][0], mat.m[2][1], mat.m[2][2]);
	quaternion = quaternion * CreateRotationQuaternion(roll, zAxis);

	// ﾋﾟｯﾁ
	auto xAxis = Vector3(mat.m[0][0], mat.m[0][1], mat.m[0][2]);
	quaternion = quaternion * CreateRotationQuaternion(pitch, xAxis);

	// ﾖｰ
	auto yAxis = Vector3(mat.m[1][0], mat.m[1][1], mat.m[1][2]);
	quaternion = quaternion * CreateRotationQuaternion(yaw, yAxis);

	Vector3 camPos = { 0, 0, camLength };	// 最初のｶﾒﾗ位置

	matRot = MMult(matRot, QuaternionToMatrix(quaternion));

	auto DL = camPos * matRot;

	auto camZAxis = Vector3(matRot.m[2][0], matRot.m[2][1], matRot.m[2][2]);

	auto rotAxis = Cross(camPos, camZAxis);

	auto transQ = CreateRotationQuaternion(roll, rotAxis);

	auto TransRotMat = QuaternionToMatrix(transQ);

	camPos = camPos * TransRotMat;

	//matRot = QuaternionToMatrix(quaternion);
	//mat = MMult(mat, matRot);         //回転×ｽｹｰﾙ

	//matTrans = MGetTranslate(VGet(0, 0, 0));
	//mat = MMult(mat, matTrans);       //移動×回転×ｽｹｰﾙ

	//cameraPos = cameraPos * mat;
	///////////////////////////////////////////

	// ｶﾒﾗ設定
	SetCameraPositionAndTargetAndUpVec(cameraPos.ConvertVec(), targetPos.ConvertVec(), cameraUpVec.ConvertVec());
}

//------------------------------------------------------
// @brief	ｶﾒﾗが向いている方向を返す
//------------------------------------------------------
Vector3 Camera::GetCameraDir()
{
	return cameraDir;
}