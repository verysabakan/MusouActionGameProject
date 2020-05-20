#include <assert.h>
#include <DxLib.h>
#include "ModelBase.h"
#include "Player.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
Player::Player(int ID)
	: ModelBase()
{
	modelID = MV1DuplicateModel(ID);
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
Player::~Player()
{
	assert(modelID == NULL);
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void Player::Initialize()
{
	pos = Vector3();
	rol = Vector3();
	scl = Vector3(0.5f, 0.5f, 0.5f);
	dir = 0.0f;
	//アニメーションセットアップ
	attachiIndex = MV1AttachAnim(modelID, 1, -1, false);
	//アニメーションのトータル時間を計測
	totalTime = MV1GetAttachAnimTotalTime(modelID, attachiIndex);
	playTime = 0;
	newKey = 0;
	oldKey = 0;
	trgKey = 0;
	SetAnimID(modelID, 1);
	//ターゲットの計算
	target = VTransform(VGet(300.0f, pos.y, pos.z), MGetRotY(rol.y));
	//「拡大縮小」「回転」「移動」の設定
	MV1SetScale(modelID, scl.ConvertVec());//②拡大縮小
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z));//回転
																				 //MV1SetRotationXYZ(model, rol);//回転
	MV1SetPosition(modelID, pos.ConvertVec());//移動
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void Player::Finalize()
{

}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void Player::Update()
{

}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void Player::Render()
{

}