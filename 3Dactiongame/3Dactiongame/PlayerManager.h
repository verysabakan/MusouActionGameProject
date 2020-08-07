//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰの管理
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "Vector3.h"
#include "AddList.h"

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class Player;
class Camera;
class ModelBase;

class PlayerManager
{
private:
	std::unique_ptr<Player> player;

public:
	PlayerManager(const WEAK_LIST& weakList);	// ｺﾝｽﾄﾗｸﾀ
	~PlayerManager();	// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();	// 初期化
	void Finalize();						// 終了処理
	void Update(const Vector3& cameraDir);	// 更新
	void Render();							// 描画

	ModelBase* GetPlayer();	// ﾌﾟﾚｲﾔｰを取得

};

