//------------------------------------------------------
// @brief	�����蔻��
// 2020 7/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "ObjectTypeConstant.h"
#include "ObjectBase.h"

// �������ߐ錾

class CollisionBase
{
public:
	CollisionBase();			// �ݽ�׸�
	virtual ~CollisionBase();	// �������z�޽�׸�

	virtual bool HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2) = 0;	// �e�����蔻�菈��:�K������
};

