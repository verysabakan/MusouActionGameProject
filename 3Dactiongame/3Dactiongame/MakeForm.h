//------------------------------------------------------
// @brief	当たり判定を行う形を形成する
// 2020 7/14 Ryosuke Iida
//------------------------------------------------------
#pragma once

#include "Vector3.h"

class MakeForm
{
private:


public:
	MakeForm();			// ｺﾝｽﾄﾗｸﾀ
	~MakeForm();		// ﾃﾞｽﾄﾗｸﾀ

	void GetHitCapsulePos(const VECTOR* Position, VECTOR* CapsulePosition1, VECTOR* CapsulePosition2);
};

