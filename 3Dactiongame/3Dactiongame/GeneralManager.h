//------------------------------------------------------
// @brief	ﾏﾈｰｼﾞｬｰを格納するためのﾘｽﾄ
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"
#include "GMList.h"

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class FlexibleCollision;

class GeneralManager
	:private GMList
{
private:
	std::unique_ptr<FlexibleCollision> fCollision;

public:
	GeneralManager(const STAGE_TYPE& sT);	// ｺﾝｽﾄﾗｸﾀ
	~GeneralManager();	// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();	// 初期化
	void Finalize();	// 終了処理
	void Update();		// 更新
	void Render();		// 描画

};

