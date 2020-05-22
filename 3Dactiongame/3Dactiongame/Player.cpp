#include <assert.h>
#include <vector>
#include <cmath>
#include <DxLib.h>
#include "ModelBase.h"
#include "Player.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
Player::Player(int mID , std::vector<int>& aID)
	: ModelBase()
{
	modelID = MV1DuplicateModel(mID);
	for (int i = 0; i < aID.size(); i++) {
		animID.push_back(aID[i]);
	}
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
Player::~Player()
{
	// 異常終了のﾁｪｯｸ
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
	// ｱﾆﾒｰｼｮﾝｾｯﾄｱｯﾌﾟ
	attachiIndex = -1;
	//for (int i = 0; i < animID.size(); i++) {
		attachiIndex = MV1AttachAnim(modelID, 0, animID[7], true);
	//}
	// ｱﾆﾒｰｼｮﾝのﾄｰﾀﾙ時間を計測
	totalTime = MV1GetAttachAnimTotalTime(modelID, attachiIndex);
	playTime = 0;
	newKey = 0;
	oldKey = 0;
	trgKey = 0;
	SetAnimID(modelID, 0);
	// ﾀｰｹﾞｯﾄの計算
	target = ConvertVec3(VTransform(VGet(300.0f, pos.y, pos.z), MGetRotY(rol.y)));
	//「拡大縮小」「回転」「移動」の設定
	MV1SetScale(modelID, scl.ConvertVec());//�A拡大縮小
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z));//回転
	// MV1SetRotationXYZ(model, rol);//回転
	MV1SetPosition(modelID, pos.ConvertVec());//移動
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void Player::Finalize()
{
	// ﾓﾃﾞﾙの削除
	MV1DeleteModel(modelID);
	modelID = NULL;
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void Player::Update()
{
	newKey = 0;
	//左右旋回
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		dir += 0.8f;
		newKey = 1;
		//ModelAnimTime(ACT_RUN);
	}


	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		dir -= 0.8f;
		newKey = 1;
	}
	rol.y = (DX_PI_F / 180)*dir;// ﾗｼﾞｱﾝに変換
	//----向いている方向に前後移動
	if (CheckHitKey(KEY_INPUT_UP))
	{
		pos.x += cosf(rol.y)*3.0f;
		pos.z -= sinf(rol.y)*3.0f;
		newKey = 1;
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		pos.x -= cosf(rol.y)*3.0f;
		newKey = 1;
		pos.z += sinf(rol.y)*3.0f;
	}

	// ﾀｰｹﾞｯﾄの計算
	target = ConvertVec3(VTransform(VGet(300.0f, 0.0f, 0.0f), MGetRotY(rol.y)));
	//「拡大縮小」「回転」「移動」の設定
	MV1SetScale(modelID, scl.ConvertVec());// �A拡大縮小2
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z)); //回転
	// MV1SetRotationXYZ(model, rol);// 回転
	MV1SetPosition(modelID, pos.ConvertVec());// 移動

	// ｱﾆﾒｰｼｮﾝの切り替え
	if ((newKey == 1) && oldKey == 0)
	{
		SetAnimID(modelID, 7);

	}
	if ((newKey == 0) && oldKey == 1)
	{
		// 停止(0番)ﾓｰｼｮﾝをｾｯﾄ
		// 歩く(7番)ﾓｰｼｮﾝをｾｯﾄ
		SetAnimID(modelID, 0);
	}
	oldKey = newKey;// 次のﾙｰﾌﾟの為の準備
	playTime += 0.5f;
	if (playTime >= totalTime)
	{
		playTime = 0.0f;
	}

	// modelにｱﾆﾒｰｼｮﾝをｾｯﾄ
	MV1SetAttachAnimTime(modelID, attachiIndex, playTime);
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void Player::Render()
{
	// 描画
	MV1DrawModel(modelID);
}