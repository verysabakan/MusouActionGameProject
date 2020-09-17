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

#include "FrameRate.h"
#include "_Debug.h"

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

	DebugDrawStart;
	DFS(500, 0, 0xffffff, "%f,%f,%f", rol.x, rol.y, rol.z);
	DFS(500, 16, 0xffffff, "%f,%f,%f", moveSpeed.x, moveSpeed.y, moveSpeed.z);
	DebugDrawEnd;
}
//------------------------------------------------------
// @brief	動作
//------------------------------------------------------
void Player::Behavior()
{
	auto newSpeed = Vector3();
	
	// ---------------
	// とりあえずのやつ
	if (lpController->IsPushC(INPUT_STATE::INPUT_TRG) && actionState != ACTION_STATE::ACTION_STATE_JUMP)
	{
		moveSpeed.y = 5.0f;
		actionState = ACTION_STATE::ACTION_STATE_JUMP;
	}
	if (lpController->IsPushA(INPUT_STATE::INPUT_TRG))
	{
		actionState = ACTION_STATE::ACTION_STATE_ATTACK1;
	}
	// ---------------

	// ｶﾒﾗ正面方向に移動
	if (lpController->IsPushUP(INPUT_STATE::INPUT_HOLD))
	{
		// 移動速度
		newSpeed = moveDir * 5.0f;
		// 進む方向の速度に変換
		moveSpeed = moveSpeed + newSpeed;
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// ｶﾒﾗの方向に移動
	if (lpController->IsPushDOWN(INPUT_STATE::INPUT_HOLD))
	{
		// 移動速度
		newSpeed = moveDir * 5.0f * -1.0f;
		// 進む方向の速度に変換
		moveSpeed = moveSpeed + newSpeed;
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// 右移動
	if (lpController->IsPushRIGHT(INPUT_STATE::INPUT_HOLD))
	{
		// 移動速度
		newSpeed = moveDir * 5.0f;
		moveSpeed = moveSpeed + newSpeed;
		// 進む方向の速度に変換
		moveSpeed = Vector3(moveSpeed.z, moveSpeed.y, -moveSpeed.x);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

	// 左移動
	if (lpController->IsPushLEFT(INPUT_STATE::INPUT_HOLD))
	{
		// 移動速度
		newSpeed = moveDir * 5.0f;
		moveSpeed = moveSpeed + newSpeed;
		// 進む方向の速度に変換
		moveSpeed = Vector3(-moveSpeed.z, moveSpeed.y, moveSpeed.x);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}

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
		moveSpeed -= otamesi * lpFrameRate->GetStepTime();
		moveSpeed.y += -9.8f * lpFrameRate->GetStepTime();
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
		if (playTime >= totalTime)
		{
			actionState = ACTION_STATE::ACTION_STATE_STANCE;
		}
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
		rol.y = atan2(-moveSpeed.x, -moveSpeed.z);
		actionState = ACTION_STATE::ACTION_STATE_RUN;
	}
	else if (actionState == ACTION_STATE::ACTION_STATE_STANCE)
	{

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
		if (actionState == ACTION_STATE::ACTION_STATE_ATTACK1)
		{
			actionState = ACTION_STATE::ACTION_STATE_STANCE;
		}
	}

	otamesi = ConvertVec3(MV1GetAttachAnimFrameLocalPosition(modelHandle, attachiIndex, 0));
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