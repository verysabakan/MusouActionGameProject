//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを撮るｶﾒﾗ
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <cmath>
#include "Vector3.h"
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
	cameraPos = Vector3(0.0f, 50.0f, -500.0f);
	targetPos = Vector3(0.0f, 0.0f, 0.0f);
	cameraUpVec = Vector3(0.0f, 1.0f, 0.0f);
	yaw = DX_PI_F / 60;
	camLength = 500.0f;		//中心からの距離
	camDir = 90.0f;
	camcnt = 0;
	//camDir = 5;
	deg = 90;
	camRol = Vector3(0.0f, 0.0f, 0.0f);
	camRol.y = (DX_PI_F / 180)*camDir;
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
	if (CheckHitKey(KEY_INPUT_F))
	{
		camLength += 5;
	}
	if (CheckHitKey(KEY_INPUT_G))
	{
		camLength -= 5;
	}

	//計算用の座標ﾓﾃﾞﾙを用意する
	auto modelPos = model->GetPosition();

	camRol = model->GetRotation();
	targetPos.x = modelPos.x + cosf(camRol.y) * 300.0f;
	targetPos.z = modelPos.z - sinf(camRol.y) * 300.0f;
	targetPos.y = 50.0f;

	// ﾀｰｹﾞｯﾄへのﾍﾞｸﾄﾙ変換
	auto camVec = ConvertVec3(VGet(targetPos.x - modelPos.x,
										targetPos.y,
											targetPos.z - modelPos.z));
	
	// ﾍﾞｸﾄﾙの正規化
	camVec = camVec.Normalized();	//単位ﾍﾞｸﾄﾙ

	// ﾍﾞｸﾄﾙ方向へｵﾌｾｯﾄする
	cameraPos.x = modelPos.x - camVec.x*camLength;
	cameraPos.y = modelPos.y + (camVec.y*camLength + standardEye);	//100.0fは標準目線
	cameraPos.z = modelPos.z - camVec.z*camLength;

	//カメラポジション
	SetCameraPositionAndTargetAndUpVec(cameraPos.ConvertVec(),
											targetPos.ConvertVec(),
												cameraUpVec.ConvertVec());
}