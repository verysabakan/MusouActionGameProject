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
    PlayerAndTerrain();
    virtual ~PlayerAndTerrain();

    bool HitCheck(const ObjectType& o1, const ObjectType& o2);  // ﾌﾟﾚｲﾔｰと地形の判定処理

};

