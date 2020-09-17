//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰと地形の当たり判定
// 2020 7/22 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "CollisionBase.h"

// PlayerAndTerrainConstant
namespace PATCon
{
	const int STAGE_OBJECT_MAX_NUM = 512;			// ｽﾃｰｼﾞﾃﾞｰﾀに含められる最大ｵﾌﾞｼﾞｪｸﾄ数、512
	const int CHARA_MAX_HITCOLL = 2048;				// 処理するｺﾘｼﾞｮﾝﾎﾟﾘｺﾞﾝの最大数、2048
	const float CHARA_ENUM_DEFAULT_SIZE = 200.0f;	// 周囲のﾎﾟﾘｺﾞﾝ検出に使用する球の初期ｻｲｽﾞ、
	const int CHARA_HIT_TRYNUM = 16;				// 壁押し出し最大試行回数、16
	const float CHARA_HIT_SLIDE_DISTANCE = 5.0f;	// 一度の壁押し出し処理でｽﾗｲﾄﾞさせる距離、5.0f
	const float CHARA_HIT_FLOOR_Y_ADJUST_JUMP = -1.0f;	// ｼﾞｬﾝﾌﾟしている際の当たり判定の座標の補正値
	const float CHARA_HIT_FLOOR_Y_ADJUST_WALK = -40.0f;	// 着地している際の当たり判定の座標の補正値
}

class PlayerAndTerrain
	:public CollisionBase
{
private:
	

public:
    PlayerAndTerrain();				// ｺﾝｽﾄﾗｸﾀ
    virtual ~PlayerAndTerrain();	// ﾃﾞｽﾄﾗｸﾀ

    virtual bool HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2) override;  // ﾌﾟﾚｲﾔｰと地形の判定処理

};

