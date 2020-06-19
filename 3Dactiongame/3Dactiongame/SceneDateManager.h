//------------------------------------------------------
// @brief	ｼｰﾝ間のﾃﾞｰﾀ管理
// 2020 6/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"

class SceneDateManager
{
private:
	STAGE_TYPE stageType;	// どのｽﾃｰｼﾞか

public:
	SceneDateManager();				// ｺﾝｽﾄﾗｸﾀ
	virtual ~SceneDateManager();	// ﾃﾞｽﾄﾗｸﾀ

	void SetStageType(const STAGE_TYPE& type);	// 選んだｽﾃｰｼﾞをｾｯﾄ
	const STAGE_TYPE GetStageType() const;	// 格納したｽﾃｰｼﾞﾀｲﾌﾟを取得

};
