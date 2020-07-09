//------------------------------------------------------
// @brief	ｽﾃｰｼﾞの構成に必要なﾃﾞｰﾀの読み込み
// 2020 6/4 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <vector>
#include <string>
#include "LoadStage.h"
#include "DxLib.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
LoadStage::LoadStage()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
LoadStage::~LoadStage()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ｽﾃｰｼﾞﾃﾞｰﾀの読み込み
// @param	mH ｽﾃｰｼﾞﾓﾃﾞﾙ用
// @param	cH ｺﾘｼﾞｮﾝ用
// @param	sH 空用
// @param	sT ｽﾃｰｼﾞの種類
// @return	成功したかどうか
//------------------------------------------------------
bool LoadStage::LoadStageDate(int& mH, int& cH, int& sH, const STAGE_TYPE& sT)
{
	// ﾊﾟｽがあればﾛｰﾄﾞする
	auto path = ConvertStageKindToPath(sT, LOAD_MODEL);
	if (path)
	{
		mH = MV1LoadModel(path);
		cH = MV1LoadModel(ConvertStageKindToPath(sT, LOAD_COLLISION));
		sH = MV1LoadModel(ConvertStageKindToPath(sT, LOAD_SKY));
	}

	// 読み込み失敗
	if (mH == -1)
	{
		// 異常終了
		return false;
	}

	// 正常終了
	return true;
}

//------------------------------------------------------
// @brief	種類をﾊﾟｽに変換する
// @param	sk ｽﾃｰｼﾞの種類
// @return	ﾌｧｲﾙのﾊﾟｽ
//------------------------------------------------------
const char* LoadStage::ConvertStageKindToPath(const STAGE_TYPE& sT, const LoadType& lT)
{
	// この辺で.txtを読み込む

	// SAMPLEだったらｻﾝﾌﾟﾙｽﾃｰｼﾞのﾊﾟｽを
	if (sT == STAGE_SAMPLE)
	{
		auto path = "Model/SampleStage/Stage01.mv1";

		if (lT == LOAD_COLLISION)
		{
			path = "Model/SampleStage/Stage01_c.mv1";
		}
		else if (lT == LOAD_SKY)
		{
			path = "Model/SampleStage/Stage01_sky.mv1";
		}
		
		return path;
	}

	return NULL;
}