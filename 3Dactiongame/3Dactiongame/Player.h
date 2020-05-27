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
		ANIM_DEFEND,
		ANIM_IDLE,
		ANIM_DIE,
		ANIM_JUMP,
		ANIM_JUMP_M,
		ANIM_CASTSPELL,
		ANIM_BACK,
		ANIM_BACK_M,
		ANIM_FORWARD,
		ANIM_FORWARD_M,
		ANIM_LEFT,
		ANIM_LEFT_M,
		ANIM_RIGHT,
		ANIM_RIGHT_M
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