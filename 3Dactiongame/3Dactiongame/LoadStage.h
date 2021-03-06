//------------------------------------------------------
// @brief	ｽﾃｰｼﾞの構成に必要なﾃﾞｰﾀの読み込み
// 2020 6/4 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"

class LoadStage
{
private:
	// 読み込むﾓﾃﾞﾙのﾀｲﾌﾟ
	typedef enum
	{
		LOAD_MODEL,
		LOAD_COLLISION,
		LOAD_SKY
	} LoadType;

public:
	LoadStage();	// ｺﾝｽﾄﾗｸﾀ
	~LoadStage();	// ﾃﾞｽﾄﾗｸﾀ

	bool LoadStageDate(int& mH, int& cH, int& sH, const STAGE_TYPE& sT);			// ｽﾃｰｼﾞﾃﾞｰﾀの読み込み

private:
	const char* ConvertStageKindToPath(const STAGE_TYPE& sT, const LoadType& lT);	// STAGE_KINDをﾊﾟｽに変換
	
};
