//------------------------------------------------------
// @brief	�����蔻����s���`���`������
// 2020 7/14 Ryosuke Iida
//------------------------------------------------------
#pragma once

#include "Vector3.h"

class MakeForm
{
private:


public:
	MakeForm();			// �ݽ�׸�
	~MakeForm();		// �޽�׸�

	void GetHitCapsulePos(const VECTOR* Position, VECTOR* CapsulePosition1, VECTOR* CapsulePosition2);
};

