//------------------------------------------------------
// @brief	��޼ު�Ă̎�ނ̊��׽
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ObjectTypeConstant.h"

class ObjectTypeBace
{
	ObjectTypeBace();				// �ݽ�׸�
	virtual ~ObjectTypeBace();		// �޽�׸�

	virtual ObjectType GetType() = 0;	
};

