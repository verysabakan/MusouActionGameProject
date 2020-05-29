//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを操る
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class ModelBase;

class Player 
	:public ModelBase
{
private:
	// 現在のｱﾆﾒｰｼｮﾝの状態、M:移動
	enum ANIM_STATE
	{
		ANIM_DEAD,
		ANIM_DOWN,
		ANIM_DAMAGE,
		ANIM_STUN,
		ANIM_JUMP,
		ANIM_SKILL1,
		ANIM_SKILL2,
		ANIM_SKILL3,
		ANIM_ATTACK1,
		ANIM_ATTACK2,
		ANIM_BROCK,
		ANIM_WALK,
		ANIM_RUN,
		ANIM_STANCE
	};

	ANIM_STATE animState;
	ANIM_STATE oldAnimState;

public:
	Player(int mID , std::vector<int>& aID);
	~Player();
	void Initialize();	// 初期化処理
	void Finalize();	// 終了処理
	void Update(const Vector3& cameraDir);		// 更新
	void Render();		// 描画

private:
	void Behavior(const Vector3& cameraDir);		// 動作
	void Animation();		// 移動
};