//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを操る
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <vector>
#include <cmath>
#include <DxLib.h>
#include "Player.h"
#include "Controller.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
Player::Player(int mID , std::vector<int>& aID)
{
	// ﾓﾃﾞﾙを読み込み、複製
	modelHandle = MV1DuplicateModel(mID);
	for (int i = 0; i < aID.size(); i++)
	{
		animHandle.push_back(aID[i]);
	}
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
Player::~Player()
{
	// 異常終了のﾁｪｯｸ
	assert(modelHandle == NULL);
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void Player::Initialize()
{
	pos = {4557, 0, 2782};
	// ｱﾆﾒｰｼｮﾝｾｯﾄｱｯﾌﾟ
	actionState = ACTION_STATE::ACTION_STATE_STANCE;
	SetAnimID(modelHandle, actionState);
	oldActionState = actionState;	// 前のｱﾆﾒｰｼｮﾝ
	playTime = 0;
	//「拡大縮小」「回転」「移動」の設定
	scl = Vector3(0.5f, 0.5f, 0.5f);
	MV1SetScale(modelHandle, scl.ConvertVec());//②拡大縮小
	MV1SetRotationXYZ(modelHandle, rol.ConvertVec());//回転
	MV1SetPosition(modelHandle, pos.ConvertVec());//移動

	gravity = 0;	// 重力
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void Player::Finalize()
{
	// ﾓﾃﾞﾙの削除
	MV1DeleteModel(modelHandle);
	modelHandle = NULL;
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void Player::Update()
{
	// 移動の更新
	Behavior();
	// ｱﾆﾒｰｼｮﾝの更新
	Animation();
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void Player::Render()
{
	// 描画
	MV1DrawModel(modelHandle);
}

//------------------------------------------------------
// @brief	動作
//------------------------------------------------------
void Player::Behavior()
{
	moveSpeed = {};

	// ---------------
	// とりあえずのやつ
	moveSpeed.y += gravity;
	pos.y += moveSpeed.y;
	if (lpController.IsPushC(INPUT_TRG) && moveSpeed.y == 0.0f)
	{
		//moveSpeed.y += 100.0f;
		//jumpFlag = true;
	}
	// ---------------

	// 入力無し:待機状態
	actionState = ACTION_STATE::ACTION_STATE_STANCE;

	moveFlag = false;

	// 行動別の処理(優先度準)
	if (actionState == ACTION_STATE::ACTION_STATE_DEAD)
	{
		
	}
	else if (actionState == ACTION_STATE::ACTION_STATE_DOWN)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_DAMAGE)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_STUN)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_JUMP)
	{
		
	}
	else if (actionState == ACTION_STATE::ACTION_STATE_SKILL1)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_SKILL2)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_SKILL3)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_ATTACK1)
	{
		
	}
	else if (actionState == ACTION_STATE::ACTION_STATE_ATTACK2)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_BROCK)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_WALK)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_RUN)
	{

	}
	else if (actionState == ACTION_STATE::ACTION_STATE_STANCE)
	{

	}

	// 右移動
	if (lpController.IsPushRIGHT(INPUT_HOLD))
	{

		// 移動速度
		moveSpeed.x = moveDir.x * 5.0f;
		moveSpeed.z = moveDir.z * 5.0f;
		// 進む方向の速度に変換
		moveSpeed = Vector3(moveSpeed.z, moveSpeed.y, -moveSpeed.x);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// 左移動
	if (lpController.IsPushLEFT(INPUT_HOLD))
	{
		// 移動速度
		moveSpeed.x = moveDir.x * 5.0f;
		moveSpeed.z = moveDir.z * 5.0f;
		// 進む方向の速度に変換
		moveSpeed = Vector3(-moveSpeed.z, moveSpeed.y, moveSpeed.x);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// ｶﾒﾗ正面方向に移動
	if (lpController.IsPushUP(INPUT_HOLD))
	{
		// 移動速度
		moveSpeed.x = moveDir.x * 5.0f;
		moveSpeed.z = moveDir.z * 5.0f;
		// 進む方向の速度に変換
		moveSpeed = Vector3(moveSpeed.x, moveSpeed.y, moveSpeed.z);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// ｶﾒﾗの方向に移動
	if (lpController.IsPushDOWN(INPUT_HOLD))
	{
		// 移動速度
		moveSpeed.x = moveDir.x * 5.0f;
		moveSpeed.z = moveDir.z * 5.0f;
		// 進む方向の速度に変換
		moveSpeed = Vector3(-moveSpeed.x, moveSpeed.y, -moveSpeed.z);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// 移動しているときの更新
	if (actionState == ACTION_STATE::ACTION_STATE_RUN)
	{
		rol.y = atan2(-moveSpeed.x, -moveSpeed.z);
		//pos.x += moveSpeed.x;
		//pos.z += moveSpeed.z;
		actionState = ACTION_STATE::ACTION_STATE_RUN;
		moveFlag = true;
	}

	// 移動、回転の設定
	MV1SetPosition(modelHandle, pos.ConvertVec());
	MV1SetRotationXYZ(modelHandle, rol.ConvertVec());
}

//------------------------------------------------------
// @brief	ｱﾆﾒｰｼｮﾝ
//------------------------------------------------------
void Player::Animation()
{
	// 前と違っていたら更新する
	if (actionState != oldActionState)
	{
		// ｱﾆﾒｰｼｮﾝの切り替え
		SetAnimID(modelHandle, actionState);
		// ひとつ前のｱﾆﾒｰｼｮﾝを保存
		oldActionState = actionState;
	}

	// ｱﾆﾒｰｼｮﾝの再生
	playTime += 0.5f;
	if (playTime >= totalTime)
	{
		playTime = 0.0f;
	}

	// modelにｱﾆﾒｰｼｮﾝをｾｯﾄ
	MV1SetAttachAnimTime(modelHandle, attachiIndex, playTime);
}

//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄの種類を取得
//------------------------------------------------------
OBJECT_TYPE Player::GetType()
{
	return OBJECT_TYPE::OBJECT_TYPE_PLAYER;
}