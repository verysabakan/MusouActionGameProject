//------------------------------------------------------
// @brief	�����蔻��
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "ObjectTypeConstant.h"

// �������ߐ錾

class CollisionBase
{
public:
	CollisionBase();			// �ݽ�׸�
	virtual ~CollisionBase();	// �������z�޽�׸�

	virtual bool HitCheck(const ObjectType& o1, const ObjectType& o2) = 0;	// �e�����蔻�菈��:�K������

};

