//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰとｽﾃｰｼﾞの当たり判定
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#include "HitCheckCharAndStage.h"
#include "Player.h"
#include "HitCheckConstant.h"
#include "Stage.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
HitCheckCharAndStage::HitCheckCharAndStage(Player* p, Stage* s)
{
	model = reinterpret_cast<ModelBase*>(p);
	stage = reinterpret_cast<StageModelBase*>(s);
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
HitCheckCharAndStage::~HitCheckCharAndStage()
{

}

//------------------------------------------------------
// @brief	床との当たり判定
//------------------------------------------------------
void HitCheckCharAndStage::HitTerrain()
{
	const int STAGE_OBJECT_MAX_NUM = 512;

	// キャラクターの周囲にあるポリゴンを検出した結果が代入される当たり判定結果構造体
	MV1_COLL_RESULT_POLY_DIM HitDim[STAGE_OBJECT_MAX_NUM + 1];

	// 当たったオブジェクトの数
	int HitNum;

	// キャラクターの周囲にあるステージポリゴンを取得する
	HitDim[HitNum] = MV1CollCheck_Sphere(
		stage->GetCollisionModelHandle(), -1,
		model->GetFramePosition(), SearchDistance);
}


