//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰと地形の当たり判定
// 2020 7/22 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "CollisionBase.h"

class PlayerAndTerrain
	:public CollisionBase
{
public:
    PlayerAndTerrain();				// ｺﾝｽﾄﾗｸﾀ
    virtual ~PlayerAndTerrain();	// ﾃﾞｽﾄﾗｸﾀ

    virtual bool HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2) override;  // ﾌﾟﾚｲﾔｰと地形の判定処理

};

