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
	animState = ANIM_STANCE;
	SetAnimID(modelHandle, animState);
	oldAnimState = animState;	// 前のｱﾆﾒｰｼｮﾝ
	playTime = 0;
	// ﾀｰｹﾞｯﾄの計算
	// target = ConvertVec3(VTransform(VGet(300.0f, pos.y, pos.z), MGetRotY(rol.y)));
	//「拡大縮小」「回転」「移動」の設定
	scl = Vector3(0.5f, 0.5f, 0.5f);
	MV1SetScale(modelHandle, scl.ConvertVec());//②拡大縮小
	MV1SetRotationXYZ(modelHandle, rol.ConvertVec());//回転
	// MV1SetRotationXYZ(model, rol);//回転
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
void Player::Update(const Vector3& cameraDir)
{
	// 移動の更新
	Behavior(cameraDir);
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
void Player::Behavior(const Vector3& cameraDir)
{
	// 入力無し:待機状態
	animState = ANIM_STANCE;

	// 移動速度
	moveSpeed = cameraDir * 5.0f;


	moveFlag = false;

	// 行動別の処理(優先度準)
	if (animState == ANIM_DEAD)
	{
		
	}
	else if (animState == ANIM_DOWN)
	{

	}
	else if (animState == ANIM_DAMAGE)
	{

	}
	else if (animState == ANIM_STUN)
	{

	}
	else if (animState == ANIM_JUMP)
	{

	}
	else if (animState == ANIM_SKILL1)
	{

	}
	else if (animState == ANIM_SKILL2)
	{

	}
	else if (animState == ANIM_SKILL3)
	{

	}
	else if (animState == ANIM_ATTACK1)
	{
		
	}
	else if (animState == ANIM_ATTACK2)
	{

	}
	else if (animState == ANIM_BROCK)
	{

	}
	else if (animState == ANIM_WALK)
	{

	}
	else if (animState == ANIM_RUN)
	{

	}
	else if (animState == ANIM_STANCE)
	{

	}

	// 右移動
	if (lpController.IsPushRIGHT(INPUT_HOLD))
	{
		// 進む方向の速度に変換
		moveSpeed = Vector3(moveSpeed.z, moveSpeed.y, -moveSpeed.x);
		animState = ANIM_RUN;
	}

	// 左移動
	if (lpController.IsPushLEFT(INPUT_HOLD))
	{
		// 進む方向の速度に変換
		moveSpeed = Vector3(-moveSpeed.z, moveSpeed.y, moveSpeed.x);
		animState = ANIM_RUN;
	}

	// ｶﾒﾗ正面方向に移動
	if (lpController.IsPushUP(INPUT_HOLD))
	{
		// 進む方向の速度に変換
		moveSpeed = Vector3(moveSpeed.x, moveSpeed.y, moveSpeed.z);
		animState = ANIM_RUN;
	}

	// ｶﾒﾗの方向に移動
	if (lpController.IsPushDOWN(INPUT_HOLD))
	{
		// 進む方向の速度に変換
		moveSpeed = Vector3(-moveSpeed.x, moveSpeed.y, -moveSpeed.z);
		animState = ANIM_RUN;
	}

	// 移動しているときの更新
	if (animState == ANIM_RUN)
	{
		rol.y = atan2(-moveSpeed.x, -moveSpeed.z);
		pos.x += moveSpeed.x;
		pos.z += moveSpeed.z;
		animState = ANIM_RUN;
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
	if (animState != oldAnimState)
	{
		// ｱﾆﾒｰｼｮﾝの切り替え
		SetAnimID(modelHandle, animState);
		// ひとつ前のｱﾆﾒｰｼｮﾝを保存
		oldAnimState = animState;
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
// @brief	ｱﾆﾒｰｼｮﾝ
//------------------------------------------------------
ObjectType Player::GetType()
{
	return ObjectType::OBJECTTYPE_PLAYER;
}