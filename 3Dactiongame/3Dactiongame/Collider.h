//------------------------------------------------------
// @brief	当たり判定
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class Player;
class Stage;
class HitCheckCharAndStage;

class Collider
{
private:
	Player* player;
	Stage* stage;
	std::unique_ptr<HitCheckCharAndStage> hcPlayerAndStage;

public:
	Collider(Player* p, Stage* s);		// ｺﾝｽﾄﾗｸﾀ
	~Collider();	// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();	// 初期化
	void Finalize();	// 終了処理
	void Update();		// 更新
	// void Render();	// 描画

};

