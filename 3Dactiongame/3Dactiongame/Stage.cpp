//------------------------------------------------------
// @brief	ｽﾃｰｼﾞの管理
// 2020 6/3 Ryosuke Iida
//------------------------------------------------------
#include <string>
#include <assert.h>
#include <memory>
#include <DxLib.h>
#include "Stage.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
Stage::Stage(const STAGE_TYPE& sT)
{
	// 生成
	std::unique_ptr<LoadStage> loadStage = std::make_unique<LoadStage>();

	// ｽﾃｰｼﾞの生成に使うﾓﾃﾞﾙを読み込む
	loadStage->LoadStageDate(modelHandle, collisionModelHandle, skyModelHandle, sT);

	// 読み込んだら必要なくなるので解放
	loadStage.reset();
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
Stage::~Stage()
{
	// 異常終了のﾁｪｯｸ
	assert(modelHandle == NULL);
	assert(collisionModelHandle == NULL);
	assert(skyModelHandle == NULL);
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void Stage::Initialize()
{
	
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void Stage::Finalize()
{

}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void Stage::Update()
{

}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void Stage::Render()
{
	// ステージ３Ｄモデルを描画
	MV1DrawModel(modelHandle);

	if (collisionModelHandle)
	{
		// ﾃﾞﾊﾞｯｸﾞ用
		MV1DrawModelDebug(collisionModelHandle, GetColor(0, 255, 0),
			FALSE, 1.0f, TRUE, FALSE);
	}
}

//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄの種類を取得
//------------------------------------------------------
OBJECT_TYPE Stage::GetType()
{
	return OBJECT_TYPE::OBJECT_TYPE_TERRAIN;
}
