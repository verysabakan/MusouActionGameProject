//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを操る
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

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
	for (int i = 0; i < aID.size(); i++) 
	{
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
	pos = {};
	rol = {};	// 正面
	angle = 0.0f;
	// ｱﾆﾒｰｼｮﾝｾｯﾄｱｯﾌﾟ
	animState = ANIM_STANCE;
	SetAnimID(modelID, animState);
	oldAnimState = animState;	// 前のｱﾆﾒｰｼｮﾝ
	playTime = 0;

	// ﾀｰｹﾞｯﾄの計算
	// target = ConvertVec3(VTransform(VGet(300.0f, pos.y, pos.z), MGetRotY(rol.y)));
	//「拡大縮小」「回転」「移動」の設定
	scl = Vector3(0.5f, 0.5f, 0.5f);
	MV1SetScale(modelID, scl.ConvertVec());//②拡大縮小
	MV1SetRotationXYZ(modelID, rol.ConvertVec());//回転
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
	MV1DrawModel(modelID);
}

//------------------------------------------------------
// @brief	動作
//------------------------------------------------------
void Player::Behavior(const Vector3& cameraDir)
{
	// 入力無し:待機状態
	animState = ANIM_STANCE;

	// 移動速度
	auto moveSpeed = cameraDir * 5.0f;

	// 
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
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		// 進む方向の速度に変換
		moveSpeed = Vector3(moveSpeed.z, moveSpeed.y, -moveSpeed.x);
		animState = ANIM_RUN;
	}

	// 左移動
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		// 進む方向の速度に変換
		moveSpeed = Vector3(-moveSpeed.z, moveSpeed.y, moveSpeed.x);
		animState = ANIM_RUN;
	}

	// ｶﾒﾗ正面方向に移動
	if (CheckHitKey(KEY_INPUT_UP))
	{
		// 進む方向の速度に変換
		moveSpeed = Vector3(moveSpeed.x, moveSpeed.y, moveSpeed.z);
		animState = ANIM_RUN;
	}

	// ｶﾒﾗの方向に移動
	if (CheckHitKey(KEY_INPUT_DOWN))
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
	}

	// 移動、回転の設定
	MV1SetPosition(modelID, pos.ConvertVec());
	MV1SetRotationXYZ(modelID, rol.ConvertVec());
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
		SetAnimID(modelID, animState);
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
	MV1SetAttachAnimTime(modelID, attachiIndex, playTime);
}