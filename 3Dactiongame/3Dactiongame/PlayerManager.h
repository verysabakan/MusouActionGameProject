//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰの管理
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "Vector3.h"

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class Player;
class Controller;
class Camera;

class PlayerManager
{
private:
	std::unique_ptr<Player> player;

public:
	PlayerManager();	// ｺﾝｽﾄﾗｸﾀ
	~PlayerManager();	// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();	// 初期化
	void Finalize();	// 終了処理
	void Update(const Controller& controll, const Vector3& cameraDir);		// 更新
	void Render();	// 描画

	Player* GetPlayer();	// ﾌﾟﾚｲﾔｰを取得
};

