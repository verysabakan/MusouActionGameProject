//------------------------------------------------------
// @brief	ｼｰﾝ間のﾃﾞｰﾀ管理
// 2020 6/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"
#include "Singleton.h"

// 定義
#define lpSceneDateManager SceneDateManager::Instance()

class SceneDateManager
	:public Singleton<SceneDateManager>
{
private:
	STAGE_TYPE stageType;	// どのｽﾃｰｼﾞか

public:
	void SetStageType(const STAGE_TYPE& type);	// 選んだｽﾃｰｼﾞをｾｯﾄ
	const STAGE_TYPE GetStageType() const;	// 格納したｽﾃｰｼﾞﾀｲﾌﾟを取得

private:
	SceneDateManager();				// ｺﾝｽﾄﾗｸﾀ
	friend Singleton<SceneDateManager>;	// ﾌﾚﾝﾄﾞｸﾗｽ
	~SceneDateManager();	// ﾃﾞｽﾄﾗｸﾀ

};
