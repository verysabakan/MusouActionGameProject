//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄの種類の基底ｸﾗｽ
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ObjectTypeConstant.h"

class ObjectTypeBace
{
	ObjectTypeBace();				// ｺﾝｽﾄﾗｸﾀ
	virtual ~ObjectTypeBace();		// ﾃﾞｽﾄﾗｸﾀ

	virtual ObjectType GetType() = 0;	
};

