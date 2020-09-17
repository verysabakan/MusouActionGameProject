//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを撮るｶﾒﾗ
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <cmath>
#include <assert.h>
#include "Camera.h"
#include "ObjectBase.h"
#include "Controller.h"
#include "FrameRate.h"

#include "_Debug.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
Camera::Camera(const std::shared_ptr<ObjectBase>& p)
{
	player = p;
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
Camera::~Camera()
{
	// 異常終了のﾁｪｯｸ
	assert(player == NULL);
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void Camera::Initialize()
{
	camLength = -230.0f;		// 中心からの初期距離
	auto pPos = player->GetPosition();
	cameraPos = { pPos.x, pPos.y, pPos.z + camLength };	// ｶﾒﾗの初期位置
	targetLookAtPos = {};				// 注視点
	cameraDir = {};						// 向き
	cameraUpVec = { 0, 1.0f, 0.0f };	// ｶﾒﾗの上方向
	SetCameraNearFar(CamCon::clipNear, CamCon::clipFar);	// ｶﾒﾗの描画範囲
	horizontal = 0;
	vertical = 0;
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void Camera::Finalize()
{
	// ﾘｿｰｽの開放
	player.reset();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void Camera::Update()
{
	// ｶﾒﾗ操作
	// 設定で変更できるようにする
	if (CheckHitKey(KEY_INPUT_F)) camLength += 5;
	if (CheckHitKey(KEY_INPUT_G)) camLength -= 5;
	// ｽﾃｨｯｸによるものに変える
	auto x = 0.0f;
	auto y = 0.0f;
	if (lpController->IsRightTiltX(x)) horizontal -= CamCon::deg1Rad * 1.5f * x;
	if (lpController->IsRightTiltY(y)) vertical -= CamCon::deg1Rad * 1.5 * y;
	

	Move();

	/*
	float roll = 0;		// roll回転
	float pitch = 0;	// pitch回転
	float yaw = 0;		// yaw回転

	MATRIX mat;
	MATRIX matRot;
	MATRIX matTrans;
	CreateIdentityMatrix(&mat);
	CreateIdentityMatrix(&matRot);
	CreateIdentityMatrix(&matTrans);

	quaternion.w = 1.0f;
	quaternion.x = quaternion.y = quaternion.z = 0;

	// ﾋﾟｯﾁ
	auto xAxis = Vector3(mat.m[0][0], mat.m[0][1], mat.m[0][2]);
	quaternion = quaternion * CreateRotationQuaternion(pitch, xAxis);

	// ﾖｰ
	auto yAxis = Vector3(mat.m[1][0], mat.m[1][1], mat.m[1][2]);
	quaternion = quaternion * CreateRotationQuaternion(yaw, yAxis);

	// ﾛｰﾙ
	auto zAxis = Vector3(mat.m[2][0], mat.m[2][1], mat.m[2][2]);
	quaternion = quaternion * CreateRotationQuaternion(roll, zAxis);

	matRot = QuaternionToMatrix(quaternion);
	mat = MMult(mat, matRot);         // 回転×ｽｹｰﾙ

	matTrans = MGetTranslate(VGet(0, 0, 0));
	mat = MMult(mat, matTrans);       // 移動×回転×ｽｹｰﾙ

	cameraPos = Vec3TransformNormal(cameraPos, mat);
	*/
}

//------------------------------------------------------
// @brief	描画:ﾃｽﾄ用
//------------------------------------------------------
void Camera::Renderer()
{
	// ﾃﾞﾊﾞｯｸﾞの時だけ描画
#ifdef _DEBUG
	DebugDrawStart;
	DFS(200, 48, 0xffffff, "%f,%f,%f", cameraPos.x, cameraPos.y, cameraPos.z);
	DFS(200, 64, 0xffffff, "%f,%f,%f", targetLookAtPos.x, targetLookAtPos.y, targetLookAtPos.z);
	DFS(200, 80, 0xffffff, "%f,%f", vertical, horizontal);
	DebugDrawEnd;
#endif // _DEBUG
}

//------------------------------------------------------
// @brief	ｶﾒﾗが向いている方向を返す
//------------------------------------------------------
Vector3 Camera::GetCameraDir()
{
	return cameraDir;
}

//------------------------------------------------------
// @brief	ｶﾒﾗの移動回転
//------------------------------------------------------
void Camera::Move()
{
	// ﾌﾟﾚｲﾔｰが存在しない場合は何もしない
	auto pc = player;
	if (pc == NULL)
	{
		return;
	}

	auto StepTime = lpFrameRate->GetStepTime();	// 推移時間
	Vector3 origPosition = cameraPos;	// 揺らしを無視した位置
	Vector3 origLookAtPosition = targetLookAtPos;	// 揺らしを無視したﾀｰｹﾞｯﾄ位置
	Vector3 shakePosition = { 0.0f, 0.0f, 0.0f };	// 揺らしたときの位置
	bool shake = false;	// 揺らすかどうか
	float shakeAngle = 0;	// 揺らす角度
	float shakeTimeCounter = 0;	// 揺ら時間のｶｳﾝﾀｰ
	float shakeTime = 1.0f;	// 揺らす時間
	float shakeWidth = 5.0f;	// 揺らす幅
	float shakeAngleSpeed = 0.5f;	// 揺らす速さ
	Vector3 TestPosition = {};

	// 水平方向の角度変更
	if (horizontal < -DX_PI_F)
	{
		horizontal += DX_TWO_PI_F;
	}
	if (horizontal > DX_PI_F)
	{
		horizontal -= DX_TWO_PI_F;
	}

	// 垂直方向の角度変更
	if (vertical < -DX_PI_F / 2.0f + 0.6f)
	{
		vertical = -DX_PI_F / 2.0f + 0.6f;
	}
	if (vertical > DX_PI_F / 2.0f - 0.6f)
	{
		vertical = DX_PI_F / 2.0f - 0.6f;
	}

	/*
	// カメラを揺らす処理を行うかどうかのフラグが立っていたらカメラを揺らす処理を行う
	if (shake)
	{
	// sin を使用した揺らし座標の算出
	shakePosition.y = sin(shakeAngle) * (1.0f - (shakeTimeCounter /
	shakeTime)) * shakeWidth;
	shakePosition.x = 0.0f;
	shakePosition.z = 0.0f;

	// 揺らし処理に使用する sin に渡す角度の変更処理
	shakeAngle += shakeAngleSpeed * StepTime;

	// 揺らす時間が経過したら揺らし処理を終了する
	shakeTimeCounter += StepTime;
	if (shakeTimeCounter >= shakeTime)
	{
	shake = false;
	}
	}
	else
	{
	// 揺らされていない場合は揺らし処理による加算座標を０にする
	shakePosition = { 0.0f, 0.0f, 0.0f };
	}
	*/

	// 目標注視点座標の算出
	targetLookAtPos = pc->GetPosition();
	targetLookAtPos.y += 70.0f;

	// 目標座標の算出
	Vector3 targetPosition;
	targetPosition.x = 0.0f;
	targetPosition.z = cos(vertical) * camLength;
	targetPosition.y = sin(vertical) * camLength;
	targetPosition.x = -sin(horizontal) * targetPosition.z;
	targetPosition.z = cos(horizontal) * targetPosition.z;

	// 算出した位置に中心の位置を加算
	targetPosition = targetPosition + targetLookAtPos;

	auto MOVE_DIV_NUM = 0.17f;
	// カメラの揺らし処理を無視したカメラの座標、注視点座標をそれぞれの目標座標に近づける
	auto MoveScale = StepTime / MOVE_DIV_NUM;

	auto TempV = targetPosition - origPosition;
	TempV = TempV * MoveScale;
	origPosition = origPosition + TempV;

	TempV = targetLookAtPos - origLookAtPosition;
	TempV = TempV * MoveScale;
	origLookAtPosition = origLookAtPosition + TempV;

	// カメラの揺らし処理を無視したカメラの座標、注視点座標にカメラの揺らし処理による
	// 加算座標を足した座標を現在のカメラの座標、注視点座標とする
	cameraPos = origPosition + shakePosition;

	auto lookAtPosition = origLookAtPosition + shakePosition;

	// カメラの座標からカメラの注視点座標へのベクトルを算出
	auto direction = (lookAtPosition - cameraPos).Normalized();

	// カメラから見て右方向のベクトルを算出
	auto rightDirection = (Cross(direction, Vector3(0.0f, -1.0f, 0.0f))).Normalized();

	// カメラの正面方向のＹ成分を抜いたベクトルを算出
	auto frontDirection = (Cross(Vector3(0.0f, -1.0f, 0.0f), rightDirection)).Normalized();
	cameraDir = frontDirection;

	/*
	// カメラ座標から注視点座標の間にコリジョン用ポリゴンが存在するかチェック
	if (Stage_HitCheck(g_CamInfo.Position, g_CamInfo.LookAtPosition, COLLISION_SIZE))
	{
	// コリジョン用ポリゴンが存在しない座標までカメラ座標を注視点に近づける

	// 注視点座標からカメラ座標へのベクトルを算出
	Direction = VNorm(VSub(g_CamInfo.Position, g_CamInfo.LookAtPosition));

	// ポリゴンに当たらない距離をセット
	NotHitDistance = 0.0f;

	// ポリゴンに当たる距離をセット
	HitDistance = PLAYER_DISTANCE;
	do
	{
	// 当たるかどうかテストする距離を算出( 当たらない距離と当たる距離の中間 )
	TestDistance = NotHitDistance + (HitDistance - NotHitDistance) / 2.0f;

	// テスト用のカメラ座標を算出
	TestPosition =
	VAdd(g_CamInfo.LookAtPosition, VScale(Direction, TestDistance));

	// 新しい座標でコリジョン用ポリゴンに当たるかテスト
	if (Stage_HitCheck(TestPosition, g_CamInfo.LookAtPosition, COLLISION_SIZE))
	{
	// 当たったら当たる距離を TestDistance に変更する
	HitDistance = TestDistance;
	}
	else
	{
	// 当たらなかったら当たらない距離を TestDistance に変更する
	NotHitDistance = TestDistance;
	}

	// HitDistance と NoHitDistance が十分に近づいていなかったらループ
	} while (HitDistance - NotHitDistance > 1.0f);

	// カメラの座標をセット
	g_CamInfo.Position = TestPosition;
	g_CamInfo.OrigPosition = TestPosition;
	}
	*/

	// リスナーの位置を変更
	//Set3DSoundListenerPosAndFrontPos_UpVecY(cameraPos.ConvertVec(), targetLookAtPos.ConvertVec());

	SetCameraPositionAndTargetAndUpVec(cameraPos.ConvertVec(), targetLookAtPos.ConvertVec(), cameraUpVec.ConvertVec());
}