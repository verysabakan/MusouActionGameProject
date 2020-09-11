//------------------------------------------------------
// @brief	��ڲ԰�ƒn�`�̓����蔻��
// 2020 7/22 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "CollisionBase.h"

class PlayerAndTerrain
	:public CollisionBase
{
public:
    PlayerAndTerrain();				// �ݽ�׸�
    virtual ~PlayerAndTerrain();	// �޽�׸�

    virtual bool HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2) override;  // ��ڲ԰�ƒn�`�̔��菈��

};

