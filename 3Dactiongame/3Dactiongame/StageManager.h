//------------------------------------------------------
// @brief	ｽﾃｰｼﾞの管理
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "ManagerBase.h"


// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class Stage;

class StageManager
	:public ManagerBase
{
private:
	std::unique_ptr<Stage> stage;

public:
	StageManager(const STAGE_TYPE& sT);		// ｺﾝｽﾄﾗｸﾀ
	~StageManager();	// ﾃﾞｽﾄﾗｸﾀ

	virtual void Initialize() override;	// 初期化
	virtual void Finalize() override;	// 終了処理
	virtual void Update() override;		// 更新
	virtual void Render() override;		// 描画

	Stage* GetStage();	// ｽﾃｰｼﾞを取得

	bool GetManagerType(MANAGER_TYPE type);	// ﾀｲﾌﾟの取得(どのﾀｲﾌﾟか確かめる)
};

