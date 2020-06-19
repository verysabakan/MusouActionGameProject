//------------------------------------------------------
// @brief	ｽﾃｰｼﾞの管理
// 2020 6/3 Ryosuke Iida
//------------------------------------------------------
#pragma once

#include "LoadStage.h"
#include "StageModelBase.h"

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class StageModelBase;

class Stage
	: private StageModelBase
{
public:
	Stage(const STAGE_TYPE& sT);	// ｺﾝｽﾄﾗｸﾀ
	~Stage();	// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();	// 初期化
	void Finalize();	// 終了処理
	void Update();		// 更新
	void Render();		// 描画

};

