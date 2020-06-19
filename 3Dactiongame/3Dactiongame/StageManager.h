//------------------------------------------------------
// @brief	ｽﾃｰｼﾞの管理
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>


// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class Stage;

class StageManager
{
private:
	std::unique_ptr<Stage> stage;

public:
	StageManager(const STAGE_TYPE& sT);		// ｺﾝｽﾄﾗｸﾀ
	~StageManager();	// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();	// 初期化
	void Finalize();	// 終了処理
	void Update();		// 更新
	void Render();	// 描画

	Stage* GetStage();	// ｽﾃｰｼﾞを取得
};

