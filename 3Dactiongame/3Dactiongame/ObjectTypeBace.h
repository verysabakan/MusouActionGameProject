//------------------------------------------------------
// @brief	��޼ު�Ă̎�ނ̊��׽
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ObjectTypeConstant.h"

class ObjectTypeBace
{
public:
	ObjectTypeBace();				// �ݽ�׸�
	virtual ~ObjectTypeBace();		// �޽�׸�

	virtual ObjectType GetType() = 0;	// ��޼ު�Ă̎�ނ��擾:�K������
};

