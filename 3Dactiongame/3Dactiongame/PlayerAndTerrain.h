//------------------------------------------------------
// @brief	��ڲ԰�ƒn�`�̓����蔻��
// 2020 7/22 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "CollisionBase.h"

class PlayerAndTerrain
	:private CollisionBase
{
public:
    PlayerAndTerrain() {}
    virtual ~PlayerAndTerrain() {}

    bool HitCheck(const ObjectType& o1, const ObjectType& o2);  // ��ڲ԰�ƒn�`�̔��菈��

};

